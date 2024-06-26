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

string s;
vector<vector<ll>> dp;

ll f(int& m) {
    for (int mask = (1 << s.size()) - 1; mask >= 0; mask--) {
        for (int curr = m - 1; curr >= 0; curr--) {
            int cnt = __builtin_popcount(mask);

            if (cnt == s.size()) {
                dp[mask][curr] = (curr == 0);
                continue;
            }

            ll ans = 0;

            for (int i = 0; i < s.size(); i++) {
                if (mask == 0 && s[i] == '0') {
                    continue;
                }

                if (!((mask >> i) & 1)) {
                    ans += dp[mask | (1 << i)][(curr * 10 + (s[i] - '0')) % m];
                    // ans += f(mask | (1 << i), ((curr * 10) + (s[i] - '0')) % m, m);
                }
            }

            dp[mask][curr] = ans;
        }
    }

    return dp[0][0];
}


vector<ll> fac(19, 1);

void HHM() {
    int  n, i, j, k;
    cin >> s >> k;

    dp.assign((1 << s.size()) + 2, vector<ll>(k + 1, -1));
    for (i = 1; i <= 18; i++) fac[i] = fac[i - 1] * i;

    ll ans = f(k);

    vector<ll> cnt(10, 0);

    for (auto x : s) {
        cnt[x - '0']++;
    }

    for (auto x : cnt) {
        ans /= fac[x];
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
