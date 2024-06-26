// #include <bits/stdc++.h>
// using namespace std;
// #define ll int

// int main() {
//     ll n, k; cin >> n >> k;
//     vector<ll>price(n), page(n);

//     for (auto& x : price) cin >> x;
//     for (auto& x : page) cin >> x;

//     vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= k; j++) {
//             if (i == 0 && j == 0) {
//                 dp[i][j] = 0; continue;
//             }
//             if (i == 0) {
//                 if (j >= price[i])dp[i][j] = page[i];
//                 else dp[i][j] = 0;
//             }
//             else if (j == 0) {
//                 dp[i][j] = 0;
//             }
//             else {
//                 dp[i][j] = dp[i - 1][j];
//                 if (j >= price[i])dp[i][j] = max(dp[i][j], page[i] + dp[i - 1][j - price[i]]);
//             }
//         }
//     }
//     cout << dp[n - 1][k] << endl;
// }


#include <bits/stdc++.h>
using namespace std;
#define ll int

int main() {
    ll n, k; cin >> n >> k;
    vector<ll>price(n), page(n);

    for (auto& x : price) cin >> x;
    for (auto& x : page) cin >> x;

    vector<vector<ll>>dp(n + 1, vector<ll>(k + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0) {
                dp[i][j] = 0; continue;
            }
            ll ans = 0;
            if (j >= price[i - 1])
                ans = page[i - 1] + dp[i - 1][j - price[i - 1]];
            dp[i][j] = max(ans, dp[i - 1][j]);
        }
    }
    
    cout << dp[n][k] << endl;
    return 0;
}
