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

// uset<ll> prime;
// void pr() {
//     vector<bool>p(100002, 1);
//     p[0] = p[1] = false;
//     for (ll i = 2; i < 100002; i++) {
//         if (p[i]) {
//             prime.insert(i);
//             for (ll j = i * i; j < 100002; j += i) {
//                 p[j] = false;
//             }
//         }
//     }
//     return;
// }

// umap<ll, bool>dp;

// ll f(ll n) {
//     if (prime.find(n) != prime.end()) {
//         if (n % 2) return true;
//         return false;
//     }
//     if (dp.find(n) != dp.end()) return dp[n];

//     bool ans = false;
//     bool flag = true;

//     for (ll i = 2; i * i <= n;i++) {
//         if (n % i == 0) {
//             if (i % 2) {
//                 flag = false;
//                 ans |= !f(n - i);
//             }
//             if (i * i != n && (n / i) % 2) {
//                 flag = false;
//                 ans |= !f(n - (n / i));
//             }
//         }
//     }
//     if (flag) return dp[n] = 0;
//     return dp[n] = ans;
// }

void HHM() {
    ll  n, i, j, k;
    cin >> n;
    // for (i = 1; i <= 100; i++) {
    //     if (i % 2 == 0)
    //         cout << i << " " << f(i) << endl;
    // }
    // for (i = 1; i <= 100; i++) {
    //     if (i % 2)
    //         cout << i << " " << f(i) << endl;
    // }
    if (n % 2 && n > 1) {
        cout << "Alice\n"; 
    }
    else {
        cout << "Bob\n"; 
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    // pr();
    while (t--) { HHM(); }
}
