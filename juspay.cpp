// हर हर महादेव 

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define dbl double
#define pb push_back
#define ll long long int
#define uset unordered_set
#define umap unordered_map
long long int mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626
#define vin(v) for(auto &z: v)cin >> z

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;


ll n, m, q;
vector<vector<ll>> g;

vector<ll> locked;
map<ll, pair<ll, ll>> mp;

map<ll, string>name;
map<string, ll>number;
map<ll, ll> locked_id;


class SegTree {
    public:
    ll n; vector<ll> tr;

    SegTree(ll size) {
        n = size; tr.assign(4 * n + 1, 0);
    }

    void upd(ll i, ll s, ll e, ll pos, ll val) {
        if (e < pos || s > pos) return;

        if (s == e && s == pos) {
            tr[i] = val;
            locked[s] = val;
            return;
        }

        ll mid = (s + e) / 2;
        upd(2 * i, s, mid, pos, val);
        upd(2 * i + 1, mid + 1, e, pos, val);

        tr[i] = tr[2 * i] + tr[2 * i + 1];
        return;
    }

    ll query(ll i, ll s, ll e, ll l, ll r) {
        if (s > r || e < l) return 0;
        if (l <= s && r >= e) return tr[i];

        ll mid = (s + e) / 2;
        ll left = query(2 * i, s, mid, l, r);
        ll right = query(2 * i + 1, mid + 1, e, l, r);

        return left + right;
    }

};

void build() {
    g.assign(n, vector<ll>());
    queue<ll> q; q.push(0);
    ll curr = 1;

    while (q.size()) {
        ll node = q.front(); q.pop();
        for (ll i = curr; i < n && i < curr + m; i++) {
            g[node].push_back(i); q.push(i);
        }
        curr = min(curr + m, n);
    }
}

ll timer = 0;

void tree_flat(ll src) {
    mp[src].first = timer++;

    for (auto x : g[src]) {
        tree_flat(x);
    }

    mp[src].second = timer++;
    return;
}

bool is_asc_locked(ll src) {
    while (src >= 0) {
        ll idx = mp[src].first;
        if (locked[idx] == 1) return 1;
        if (src == 0) return 0;
        src = (src - 1) / m;
    }

    return 0;
}

bool is_desc_locked(ll src, SegTree& st) {
    ll l_idx = mp[src].first, r_idx = mp[src].second;
    return st.query(1, 0, locked.size() - 1, l_idx, r_idx) != 0;
}

bool lockVertex(ll u, ll uid, SegTree& st) {
    if (is_asc_locked(u)) return false;
    if (is_desc_locked(u, st)) return false;

    ll l_idx = mp[u].first, r_idx = mp[u].second;

    st.upd(1, 0, locked.size() - 1, l_idx, 1);
    st.upd(1, 0, locked.size() - 1, r_idx, 1);

    locked_id[u] = uid;
    return true;
}

bool unlockVertex(ll u, ll uid, SegTree& st) {
    if (locked_id.find(u) == locked_id.end()) return false;
    if (locked_id[u] != uid) return false;

    locked_id.erase(u);

    ll l_idx = mp[u].first, r_idx = mp[u].second;

    st.upd(1, 0, locked.size() - 1, l_idx, 0);
    st.upd(1, 0, locked.size() - 1, r_idx, 0);

    return true;
}

bool upgrade(ll u, ll uid, SegTree& st) {
    if (is_asc_locked(u)) return false;

    ll l_idx = mp[u].first, r_idx = mp[u].second;

    uset<ll> all_uid, all_node;
    
    for (auto x : locked_id) {
        ll ll_idx = mp[x.first].first, rr_idx = mp[x.first].second;

        if (l_idx < ll_idx && rr_idx < r_idx) {
            all_uid.insert(x.second);

            if (all_uid.size() > 1) return false;
            all_node.insert(x.first);
        }
    }

    if (all_uid.size() > 0 && *all_uid.begin() != uid) return false;

    for (auto x : all_node) {
        unlockVertex(x, uid, st);
    }

    lockVertex(u, uid, st);
    return true;
}

void HHM() {
    cin >> n >> m >> q; // m-ary

    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        name[i] = s; number[s] = i;
    }

    build();
    tree_flat(0);
    locked.assign(timer, 0);

    SegTree st(timer + 1);

    while (q--) {
        ll op, id; string s;
        cin >> op >> s >> id;

        if (op == 1) {
            if (lockVertex(number[s], id, st)) cout << "true" << endl;
            else cout << "false" << endl;
        }
        else if (op == 2) {
            if (unlockVertex(number[s], id, st)) cout << "true" << endl;
            else cout << "false" << endl;
        }
        else {
            if (upgrade(number[s], id, st))cout << "true" << endl;
            else cout << "false" << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
