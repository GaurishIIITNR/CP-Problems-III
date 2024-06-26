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
//     cin >> n >> k;
//     vector<ll>a(n - 1); vin(a);
//     vector<ll>b(n - 1); vin(b);

//     vector<vector<ll>>dp(n + 1, vector<ll>(2, 0));

//     dp[0][0] = a[0];
//     dp[0][1] = b[0] + k;

//     cout << 0 << " " << min(dp[0][0], dp[0][1]) << " ";

//     for (int i = 1; i < n - 1; i++) {
//         dp[i][0] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
//         dp[i][1] = min(dp[i - 1][1] + b[i], dp[i - 1][0] + b[i] + k);
//         cout << min(dp[i][0], dp[i][1]) << " ";
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     // freopen("input.txt", "r", stdin); 
//     // freopen("output.txt", "w", stdout);
//     ll t = 1;
//     // cin >> t;
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

vector<vector<ll>>dp;

ll f(vector<ll>& a, vector<ll>& b, ll i, bool curr, ll k) {
    if (i == 0) {
        if (curr) return dp[i][curr] = k + b[0];
        else return dp[i][curr] = a[0];
    }
    if (dp[i][curr] != -1) return dp[i][curr];

    if (curr) {
        return dp[i][curr] = min(k + b[i] + f(a, b, i - 1, 0, k), f(a, b, i - 1, 1, k) + b[i]);
    }
    else {
        return dp[i][curr] = min(f(a, b, i - 1, 0, k) + a[i], f(a, b, i - 1, 1, k) + a[i]);
    }
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k; n--;
    dp.assign(n + 1, vector<ll>(2, -1));

    vector<ll>a(n), b(n);
    vin(a); vin(b);

    f(a, b, n - 1, 0, k);
    f(a, b, n - 1, 1, k);

    cout << 0 << " ";
    for (int i = 0;i < n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " \n"[i == n - 1];
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
