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

string ss;

vector<vector<vector<ll>>> dp;

ll f(ll cnt, ll i, bool t) {

    if (i == ss.size()) {
        return 1;
    }

    if (dp[cnt][i][t] != -1) return dp[cnt][i][t];

    ll ans = 0;

    int st = 0, en = t ? ss[i] - '0' : 9;
    for (int j = st; j <= en; j++) {
        if (j > 0) {
            if (cnt > 0) ans += f(cnt - 1, i + 1, (t && (j == en)));
            ans %= mod;
        }
        else {
            ans += f(cnt, i + 1, (t && (j == en)));
            ans %= mod;
        }
    }

    return dp[cnt][i][t] = ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    dp.assign(4, vector<vector<ll>>(20, vector<ll>(2, -1)));
    
    ss = to_string(k);
    ll ans = f(3, 0, 1);

    dp.assign(4, vector<vector<ll>>(20, vector<ll>(2, -1)));

    ss = to_string(n - 1);
    ans -= f(3, 0, 1);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
