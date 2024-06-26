//--------------------Recursive Approach--------------------

// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 1e9 + 7;

// vector<int> dp;

// int f(int sm) {
//     if (sm == 0) return 1;
//     if (dp[sm] != -1) return dp[sm];

//     long long ans = 0;
//     for (int i = 1; i <= 6 && i <= sm; i++) {
//         ans += f(sm - i); ans %= mod;
//     }

//     return dp[sm] = ans;
// }

// int main() {
//     int sm; cin >> sm;
//     dp.assign(sm + 1, -1);
//     cout << f(sm);
//     return 0;
// }

//--------------------Iterative Approach--------------------

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;


int f(int n) {
    vector<int>dp(n + 1);
    
    for (int sm = 0; sm <= n; sm++) {
        if (sm == 0) {
            dp[sm] = 1; continue;
        }
        long long ans = 0;
        for (int i = 1; i <= 6 && i <= sm; i++) {
            ans += dp[sm - i]; ans %= mod;
        }
        dp[sm] = ans;
    }

    return dp[n];
}

int main() {
    int sm; cin >> sm;
    cout << f(sm);
    return 0;
}