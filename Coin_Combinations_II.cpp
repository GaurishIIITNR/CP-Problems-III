#include <bits/stdc++.h>
using namespace std;

int dp[101][1000001];
const int mod = 1e9 + 7;

int f(vector<int>v, int k) {
    int n = v.size();
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            if (i == n) {
                if (j == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
                continue;
            }
            if (j >= v[i]) {
                dp[i][j] = ((dp[i][j - v[i]] % mod) + (dp[i + 1][j] % mod)) % mod;
            }
            else dp[i][j] = dp[i + 1][j] % mod;
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[0][k] % mod;
}

int main() {
    int n, k;cin >> n >> k;
    vector<int>v(n); for (auto& x : v) cin >> x;
    cout << f(v, k) << endl;
}