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

vector < vector<vector<ll>>> dp;

ll f(vector<ll>& v, ll& x, ll& y, ll& n, ll i, ll cnt, ll p) {
    if (i == v.size()) {
        if (cnt < x) return INT_MAX;
        return 0;
    }
    if (dp[i][cnt][p] != -1) return dp[i][cnt][p];

    ll ans = INT_MAX;
    if (p == 1) {
        if (cnt < x) ans = min(ans, n - v[i] + f(v, x, y, n, i + 1, cnt + 1, 1));
        else if (cnt + 1 > y) ans = min(ans, v[i] + f(v, x, y, n, i + 1, 1, 0));
        else {
            ans = min(ans, n - v[i] + f(v, x, y, n, i + 1, cnt + 1, 1));
            ans = min(ans, v[i] + f(v, x, y, n, i + 1, 1, 0));
        }
    }
    else {
        if (cnt < x) ans = min(ans, v[i] + f(v, x, y, n, i + 1, cnt + 1, 0));
        else if (cnt + 1 > y) ans = min(ans, n - v[i] + f(v, x, y, n, i + 1, 1, 1));
        else {
            ans = min(ans, v[i] + f(v, x, y, n, i + 1, cnt + 1, 0));
            ans = min(ans, n - v[i] + f(v, x, y, n, i + 1, 1, 1));
        }
    }

    return dp[i][cnt][p] = ans;
}

void HHM() {
    ll  n, i, j, k, x, y, m;
    cin >> n >> m >> x >> y;

    vector<string> s(n);
    vin(s);

    vector<ll> v(m, 0);
    for (i = 0; i < m; i++) {
        ll cnt = 0;
        for (j = 0; j < n; j++) {
            if (s[j][i] == '#') cnt++;
        }
        v[i] = cnt;
    }

    dp.assign(m + 1, vector<vector<ll>>(m + 1, vector<ll>(2, -1)));
    cout << min(v[0] + f(v, x, y, n, 1, 1, 0), n - v[0] + f(v, x, y, n, 1, 1, 1)) << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
