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

bool dp[2][1005];

bool  f(vector<ll>& v, ll& m) {
    for (ll i = v.size(); i >= 0; i--) {
        for (ll tar = 0; tar <= m; tar++) {
            if (i == v.size()) {
                if (tar == 0) dp[i & 1][tar] = true;
                else dp[i & 1][tar] = false;
                continue;
            }

            dp[i & 1][tar] = dp[(i + 1) & 1][tar] | dp[(i + 1) & 1][(tar + v[i]) % m];
        }
    }

    return dp[0][m];
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    vector<ll> v(n); vin(v);

    if (n >= k) {
        cout << "YES";
        return;
    }

    bool ans = f(v, k);
    
    if (ans) cout << "YES";
    else cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
