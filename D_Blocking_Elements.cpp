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

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

vector<ll>tr;

ll query(ll i, ll s, ll e, ll l, ll r) {
    if (s > r || e < l) return LLONG_MAX;
    if (s >= l && e <= r) return tr[i];
    ll mid = s + (e - s) / 2;
    ll left = query(2 * i, s, mid, l, r);
    ll right = query(2 * i + 1, mid + 1, e, l, r);
    return min(left, right);
}

void upd(ll i, ll s, ll e, ll idx, ll val) {
    if (s == e && s == idx) {
        tr[i] = val; return;
    }
    if (s > idx || e < idx) return;
    ll mid = s + (e - s) / 2;
    upd(2 * i, s, mid, idx, val);
    upd(2 * i + 1, mid + 1, e, idx, val);
    tr[i] = min(tr[2 * i], tr[2 * i + 1]);
}

vector<ll>pref;

ll ok(vector<ll>& v, ll tot) {
    vector<ll> dp(v.size() + 1);

    for (int i = v.size(); i >= 0; i--) {
        ll uval = 0;
        if (i == v.size()) {
            dp[i] = uval = 0;
            if (i - 1 >= 0) uval += v[i - 1];
            upd(1, 0, v.size(), i, uval);
            continue;
        }
        ll curr = 0;
        ll ans = LLONG_MAX;

        ll st = 0, en;
        if (i - 1 >= 0)st = pref[i - 1];
        en = st + tot;
        ll idx = upper_bound(all(pref), en) - pref.begin();

        dp[i] = uval = query(1, 0, v.size(), i + 1, idx);

        if (idx == v.size()) {
            dp[i] = uval = 0;
            if (i - 1 >= 0)uval += v[i - 1];
            upd(1, 0, v.size(), i, uval);
            continue;
        }

        dp[i] = uval = query(1, 0, v.size(), i + 1, idx + 1);
        if (i - 1 >= 0)uval += v[i - 1];
        upd(1, 0, v.size(), i, uval);
    }

    return dp[0];
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    tr.assign((4 * (n + 1) + 1), LLONG_MAX);
    pref.assign(n, 0);

    vector<ll>v(n);
    vin(v);

    for (i = 0; i < n; i++) {
        pref[i] += v[i];
        if (i - 1 >= 0) pref[i] += pref[i - 1];
    }


    ll tot = 0;
    for (auto& x : v) tot += x;

    ll l = 0, h = tot;
    while (l < h) {
        ll mid = l + (h - l) / 2;
        if (ok(v, mid) <= mid) {
            h = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
