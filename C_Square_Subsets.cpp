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

// // vector<ll>fact;
// // vector<ll>ifact;

// // ll binpow(ll a, ll b) {
// //     ll res = 1;
// //     while (b > 0) {
// //         if (b & 1) res = (res * a) % mod;
// //         a = (a * a) % mod;
// //         b >>= 1;
// //     }
// //     return res;
// // }

// // ll iverse(ll a) {
// //     return binpow(a, mod - 2);
// // }

// // ll ncr(ll n, ll r) {
// //     if (r > n) return 0;
// //     ll ans = fact[n];
// //     ans = (ans * ifact[r]) % mod;
// //     ans = (ans * ifact[n - r]) % mod;
// //     return ans;
// // }

// vector<ll>pr;
// umap<ll, ll>mp;

// void prm() {
//     for (ll i = 2; i < 71; i++) {
//         bool f = 0;
//         for (ll j = 2; j * j <= i; j++) {
//             if (i % j == 0) {
//                 f = 1; break;
//             }
//         }
//         if (!f) {
//             pr.pb(i); mp[i] = pr.size() - 1;
//         }
//     }
//     vout(pr);
// }

// ll f(vector<ll>& v, ll mask, ll i) {
    
// }

// void HHM() {
//     ll  n, i, j, k;

//     cin >> n; prm();
//     vector<ll>v(n); vin(v);

//     // fact.assign(n + 2, 0);
//     // ifact.assign(n + 2, 0);

//     // for (i = 0; i < n + 1; i++) {
//     //     if (i == 0) {
//     //         fact[i] = 1;
//     //         ifact[i] = iverse(fact[i]);
//     //     }
//     //     else {
//     //         fact[i] = (fact[i - 1] * i) % mod;
//     //         ifact[i] = iverse(fact[i]); ifact[i] %= mod;
//     //     }
//     // }

//     vector<ll>cnt(71, 0);

//     for (i = 2; i * i <= 70; i++) {
//         for (auto& x : v) {
//             ll y = i * i;
//             while (x % y == 0) {
//                 x /= y;
//             }
//         }
//     }

//     for (auto x : v) {
//         cnt[x]++;
//     }


//     // ll ans = f(cnt); ans %= mod;
//     // ans *= binpow(2, cnt[1]); ans %= mod; ans--;
//     // ans += mod; ans %= mod;

//     // cout << ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     // freopen("input.txt", "r", stdin); 
//     // freopen("output.txt", "w", stdout);
//     ll t = 1;
//     // cin >> t;
//     while (t--) { HHM(); }
// }
