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

// // vector<ll>dp;

// ll f(vector<ll>& v, ll l, ll r) {
//     if (l == r) {
//         return 1;
//     }

// }

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n;  vector<ll>v;

//     for (i = 0; i < n; i++) {
//         ll d; cin >> d;
//         if (v.size() == 0)v.pb(d);
//         else if (v.back() != d)v.pb(d);
//     }

//     n = v.size();

//     // dp.assign(n + 1, -1);
//     cout << f(v, 0) - 1 << endl;

// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     // freopen("input.txt", "r", stdin); 
//     // freopen("output.txt", "w", stdout);
//     ll t = 1;
//     // cin >> t;
//     while (t--) { HHM(); }
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, k; cin >> n >> k;
//     vector<int> v(n);

//     for (auto& x : v) {
//         cin >> x;
//     }

//     cout << f(v, k) << endl;
// }


// #include <bits/stdc++.h>

// using namespace std;

// class Node {
// public:
//     int l, r, v;
// };

// class SegT {
// public:
//     vector<Node*> tr;

//     SegT(int n) {
//         tr.resize(4 * n);
//         for (int i = 0; i < tr.size(); ++i)
//             tr[i] = new Node();
//         bld(1, 1, n);
//     }

    // ~SegT() {
    //     for (int i = 0; i < tr.size(); ++i)
    //         delete tr[i];
    // }

    // void bld(int u, int l, int r) {
    //     tr[u]->l = l;  
    //     tr[u]->r = r;
    //     if (l == r) return;
    //     int mid = (l + r) >> 1;
    //     bld(u << 1, l, mid);
    //     bld((u << 1) | 1, mid + 1, r);
    // }

    // void mod(int u, int x, int v) {
    //     if (tr[u]->l == x && tr[u]->r == x) {
    //         tr[u]->v = v;
    //         return;
    //     }
    //     int mid = (tr[u]->l + tr[u]->r) >> 1;
    //     if (x <= mid) {
    //         mod(u << 1, x, v);
    //     } else {
    //         mod((u << 1) | 1, x, v);
    //     }
    //     pup(u);
    // }

    // void pup(int u) {
//         tr[u]->v = max(tr[u << 1]->v, tr[(u << 1) | 1]->v);
//     }

//     int qry(int u, int l, int r) {
//         if (tr[u]->l >= l && tr[u]->r <= r)
//             return tr[u]->v;

//         int mid = (tr[u]->l + tr[u]->r) >> 1;
//         int v = 0;

//         if (l <= mid)
//             v = qry(u << 1, l, r);

//         if (r > mid)
//             v = max(v, qry((u << 1) | 1, l, r));

//         return v;
//     }
// };

// int lenLIS(vector<int>& nums, int k) {
//     SegT* tree = new SegT(*max_element(nums.begin(), nums.end()) + 1);
//     int plc = 1;

//     for (int v : nums) {
//         int t = tree->qry(1, max(1, v - k), v - 1) + 1;
//         plc = max(plc, t);
//         tree->mod(1, v, t);
//     }

//     int result = plc;
//     delete tree;
//     return result;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> arr(n);
//     for (auto& i : arr) {
//         cin >> i;
//     }
//     int c = lenLIS(arr, k);
//     cout << c << endl;

// }





#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int

typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;


int main() {
    ll t; cin >> t;
    while (t--) {

        ll n, k;cin >> n;
        vector<ll> v(n);

        for (auto& x : v)
            cin >> x;

        cin >> k;
        multisat pos, neg;

        while (k--) {
            ll a, b; cin >> a >> b;
            pos.insert(a);
            neg.insert(b + 1);
        }

        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            ll x = pos.order_of_key(v[i] + 1);
            ll y = neg.order_of_key(v[i] + 1);
            if (x - y > 0)cnt++;
        }

        cout << cnt << endl;
    }
}



