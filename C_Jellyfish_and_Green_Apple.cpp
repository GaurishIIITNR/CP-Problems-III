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

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n >> k; n %= k;
//     if (n == 0) {
//         cout << 0 << endl; return;
//     }
//     ll ans = 0;
//     while (n > 0) {
//         if ((ll)log2(n) == (ll)log2(k)) {
//             bitset<64> b = k, a = n;
//             for (i = 0;i < 64;i++) {
//                 if (!a[i] && b[i]) {
//                     cout << -1 << endl; return;
//                 }
//             }
//              n %= k;
//         }
//         ans += n;
//         n *= 2;
//     }
//     cout << ans << endl;
//     // bitset<64> b = k, a = n;
//     // ll ans = 0;
//     // j = 63;
//     // while (!a[63]) {
//     //     a <<= 1;
//     //     n *= 2;
//     //     j--;
//     // }
//     // while (!b[63]) {
//     //     b <<= 1;
//     // }
//     // j = 63 - j;
//     // // for (i = 63; i >= 0; i--) {
//     // //     cout << a[i];
//     // // } cout << endl;
//     // while (a.count() && j >= 0) {
//     //     if (a == b) break;
//     //     for (i = 63; i >= 0; i--) {
//     //         if (!a[i] && b[i]) {
//     //             cout << -1 << endl; return;
//     //         }
//     //     }

//     //     ll sm = 0;
//     //     for (k = 63;k >= 0 && k >= j; k--) {
//     //         sm *= 2; sm += a[k];
//     //     }
//     //     ans += sm;
//     //     j--; a <<= 1;
//     // }
//     // cout << ans << endl;


//     // n %= k; ll n1 = n;
//     // ll ans = 0;
//     // while (n < k && n > 0) {
//     //     ans += n;
//     //     n *= 2;
//     // }

//     // if (n == k || n == 0) {
//     //     cout << ans << endl; return;
//     // }
//     // else if ((k & (k - 1)) != 0) {
//     //     cout << -1 << endl; return;
//     // }
//     // ans = 0;
//     // n = n1;
//     // while (n > 0) {
//     //     ans += n;
//     //     n *= 2;  n %= k;
//     // }
//     // cout << ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     ll t = 1;
//     cin >> t;
//     while (t--) { HHM(); }
// }
// // freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);


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

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    n = n % k;
    umap<ll, bool>mp;
    ll ans = 0;
    ll x = 80;
    while (n > 0 && x > 0) {
        if (mp.find(n) != mp.end()) {
            cout << -1 << endl; return;
        }
        mp[n] = true;
        ans += n;
        n *= 2;  n %= k;
        x--;
    }
    if (x == 0) {
        cout << -1 << endl; return;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);