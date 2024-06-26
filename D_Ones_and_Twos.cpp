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
// #define ll int
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
//     cin >> n >> k;
//     vector<ll>v(n); vin(v);

//     for (i = 1; i < n; i++) {
//         v[i] += v[i - 1];
//     }

//     while (k--) {
//         ll x; cin >> x;
//         if (x == 1) {
//             ll val; cin >> val;

//         }
//         else {
//             ll p, val; cin >> p >> val; --p;

//         }

//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     // freopen("input.txt", "r", stdin); 
//     // freopen("output.txt", "w", stdout);
//     ll t = 1;
//     cin >> t;
//     while (t--) { HHM(); }
// }


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
#define ll int
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
    vector<ll>v(n); vin(v);
    ll c = 0;

    for (i = 0; i < n;i++) {
        if (v[i] == 1) c++;
    }

    while (k--) {
        ll x; cin >> x;
        if (x == 1) {
            ll val; cin >> val;
            ll t = n - c;  ll rt = val / 2, ro = val % 2;

            if (ro == 0 && t + (c / 2) >= rt) {
                cout << "YES\n"; continue;
            }

            if (c > 0 && ro == 1 && t + ((c - 1) / 2) >= rt) {
                cout << "YES\n";  continue;
            }

            cout << "NO\n";
        }
        else {
            ll p, val; cin >> p >> val; --p;
            if (v[p] == 1 && val != v[p]) c--;
            v[p] = val;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}