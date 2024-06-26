// // हर हर महादेव

// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define F first
// #define S second
// #define dbl double
// #define pb push_back
// #define ll long long int
// #define uset unordered_set
// #define umap unordered_map
// long long int mod = 1000000007;
// #define all(x) x.begin(), x.end()
// #define Pi 3.1415926535897932384626

// #define vin(v) for(auto &x:v)cin >> x
// #define deb(v) cout << #v << " " << v << "\n"
// #define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
// #define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

// typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;


// class SegTree {
//     public:
//     ll n; vector<ll> tr, lazy;

//     // Constructor
//     SegTree(ll size) {
//         n = size;
//         tr.assign(4 * n + 1, 0);
//         lazy.assign(4 * n + 1, 0);
//     }

//     // update a node with left and right child
//     void updateNode(ll i) {
//         tr[i] = min(tr[2 * i], tr[2 * i + 1]); return;
//     }

//     //Build a tree
//     void build(vector<ll>& a, ll i, ll s, ll e) {
//         if (s == e) {
//             tr[i] = a[s]; return;
//         }
//         ll mid = (s + e) / 2;
//         build(a, 2 * i, s, mid);
//         build(a, 2 * i + 1, mid + 1, e);
//         updateNode(i);  return;
//     }

//     //Resolve the lazy propagation of a node
//     // Flag for checking if the node is leaf or not
//     void resolveLazy(ll i, bool flag) {
//         tr[i] += lazy[i];
//         if (flag) {
//             lazy[2 * i] += lazy[i];
//             lazy[2 * i + 1] += lazy[i];
//         }
//         lazy[i] = 0; return;
//     }

//     //Range update with lazy propagation
//     void rangeUpdate(ll i, ll s, ll e, ll l, ll r, ll val) {
//         if (lazy[i]) {
//             resolveLazy(i, (s != e));
//         }
//         if (s > e || l > e || r < s) return;
//         if (l <= s && e <= r) {
//             lazy[i] += val;
//             resolveLazy(i, (s != e)); return;
//         }
//         ll mid = (s + e) / 2;
//         rangeUpdate(2 * i, s, mid, l, r, val);
//         rangeUpdate(2 * i + 1, mid + 1, e, l, r, val);
//         updateNode(i); return;
//     }

//     //Range query with lazy propagation
//     ll rangeQuery(ll i, ll s, ll e, ll l, ll r) {
//         if (lazy[i]) {
//             resolveLazy(i, (s != e));
//         }
//         if (s > e || l > e || r < s) return INT_MAX;
//         if (l <= s && e <= r) {
//             return tr[i];
//         }
//         ll mid = (s + e) / 2;
//         ll left = rangeQuery(2 * i, s, mid, l, r);
//         ll right = rangeQuery(2 * i + 1, mid + 1, e, l, r);
//         return min(left, right);
//     }
// };

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n >> k;
//     vector<ll> a(n); vin(a);
//     SegTree st(n);
//     st.build(a, 1, 0, n - 1);
//     // vout(st.tr);
//     for (i = 0; i < k; i++) {
//         char c; cin >> c;
//         if (c == 'u') {
//             ll l, r, val; cin >> l >> r >> val; --l, --r;
//             st.rangeUpdate(1, 0, n - 1, l, r, val);
//         }
//         else {
//             ll l, r; cin >> l >> r; --l, --r;
//             cout << st.rangeQuery(1, 0, n - 1, l, r) << "\n";
//         }
//     }

// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     ll t = 1;
//     // cin >> t;
//     while (t--) { HHM(); }
// }
// // freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

class SegTree {
    public:
    ll n; vector<ll> tr, lazy;

    // Constructor
    SegTree(ll size) {
        n = size;
        tr.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }

    // update a node with left and right child
    void updateNode(ll i) {
        tr[i] = max(tr[2 * i], tr[2 * i + 1]); return;
    }

    //Build a tree
    void build(vector<ll>& a, ll i, ll s, ll e) {
        if (s == e) {
            tr[i] = a[s]; return;
        }
        ll mid = (s + e) / 2;
        build(a, 2 * i, s, mid);
        build(a, 2 * i + 1, mid + 1, e);
        updateNode(i);  return;
    }

    // Update a node
    void update(ll i, ll s, ll e, ll pos, ll val) {
        if (e < pos || s > pos) return;

        if (s == e && s == pos) {
            tr[i] = val; return;
        }

        ll mid = (s + e) / 2;
        update(2 * i, s, mid, pos, val);
        update(2 * i + 1, mid + 1, e, pos, val);
        updateNode(i); return;
    }

    // Query for without lazy propagation
    ll query(ll i, ll s, ll e, ll l, ll r) {
        if (s > e) return 0;
        if (l <= s && r >= e) return tr[i];
        ll mid = (s + e) / 2;
        ll left = query(2 * i, s, mid, l, r);
        ll right = query(2 * i + 1, mid + 1, e, l, r);
        return max(left, right);
    }

    //Resolve the lazy propagation of a node
    // Flag for checking if the node is leaf or not
    void resolveLazy(ll i, bool flag) {
        tr[i] = lazy[i];
        if (flag) {
            lazy[2 * i] = lazy[i];
            lazy[2 * i + 1] = lazy[i];
        }  lazy[i] = 0; return;
    }

    //Range update with lazy propagation
    void rangeUpdate(ll i, ll s, ll e, ll l, ll r, ll val) {
        if (lazy[i]) {
            resolveLazy(i, (s != e));
        }
        if (s > e || l > e || r < s) return;
        if (l <= s && e <= r) {
            lazy[i] = val;
            resolveLazy(i, (s != e));
            return;
        }
        ll mid = (s + e) / 2;
        rangeUpdate(2 * i, s, mid, l, r, val);
        rangeUpdate(2 * i + 1, mid + 1, e, l, r, val);
        updateNode(i);
    }

    //Range query with lazy propagation
    ll rangeQuery(ll i, ll s, ll e, ll l, ll r) {
        if (lazy[i]) {
            resolveLazy(i, (s != e));
        }
        if (s > e || l > e || r < s) return 0;
        if (l <= s && e <= r) {
            return tr[i];
        }
        ll mid = (s + e) / 2;
        ll left = rangeQuery(2 * i, s, mid, l, r);
        ll right = rangeQuery(2 * i + 1, mid + 1, e, l, r);
        return max(left, right);
    }
};