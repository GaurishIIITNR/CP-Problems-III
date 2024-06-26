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

#ifndef ONLINE_JUDGE
#include "debug.h"
using namespace debug;
#else 
#define deb(x)
#endif

ll binp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a; res %= mod;
        a *= a; a %= mod;
        b >>= 1;
    }

    return res;
}

ll x;
vector<vector<ll>> dp;

ll f(ll& k, ll& n, ll i, bool fl) {
    if (i == k) {
        if (fl) return 0;
        return 1;
    }

    if (dp[i][fl] != -1) return dp[i][fl];

    ll ans;

    if (n % 2) {
        ans = (x - 1) * f(k, n, i + 1, 1); ans %= mod;
        ans += (x + 1) * f(k, n, i + 1, fl); ans %= mod;
    }
    else {
        ans = x * f(k, n, i + 1, 1); ans %= mod;
        ans += (x - 1) * f(k, n, i + 1, fl); ans %= mod;
        ans += f(k, n, i + 1, 0); ans %= mod;
    }


    return dp[i][fl] = ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    x = binp(2, n - 1);
    dp.assign(k + 1, vector<ll>(3, -1));

    cout << f(k, n, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
