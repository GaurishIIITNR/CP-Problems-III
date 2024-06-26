#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod = 1e9 + 7;

int main() {
    ll n, k; cin >> n >> k;
    vector<int>v(n); for (auto& x : v)cin >> x;
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n;i++) {
        if (v[i] != 0) {
            if (v[i] > k) {
                cout << 0 << endl;
                return 0;
            }

            if (i == 0) {
                dp[i][v[i]] = 1;
                continue;
            }

            for (int j = v[i] - 1; j <= v[i] + 1; j++) {
                if (j >= 1 && j <= k) {
                    dp[i][v[i]] += dp[i - 1][j];
                    dp[i][v[i]] %= mod;
                }
            }
            continue;
        }
        for (int j = 1; j <= k; j++) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    if (jj >= 1 && jj <= k) {
                        dp[i][j] += dp[i - 1][jj];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0;j <= k; j++) {
    //         cout << dp[i][j] << " ";
    //     } cout << endl;
    // }

    ll ans = 0;
    for (int j = 1;j <= k; j++) {
        ans += dp[n - 1][j];
    }
    cout << ans % mod << endl;
}
