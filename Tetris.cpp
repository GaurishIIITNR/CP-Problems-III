// हर हर महादेव

#include <bits/stdc++.h>
using namespace std;
#define ll int

ll dp[(ll)1e5 + 1][2];
ll mod = 1e9 + 7;

ll f(ll i, bool j) {
    if (i == 1 && j == 1) {
        return dp[i][j] = 1;
    }
    if (i == 2 && j == 1) {
        return dp[i][j] = 1;
    }
    if (i == 3 && j == 1) {
        return  dp[i][j] = 3;
    }
    if (i == 4 && j == 1) {
        return dp[i][j] = 4;
    }

    if (i == 0) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];

    long long int ans = 0;
    for (ll k = 1; k < 5; k++) {
        if (i - k >= 0) {
            if (k == 1) {
                ans += f(i - k, 1 - j);
                ans %= mod;
            }
            else {
                ans += f(i - k, j);
                ans %= mod;
            }
        }
    }
    return dp[i][j] = ans;

}
void HHM() {
    ll  n, i, j, k;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n, 1) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
