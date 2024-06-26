#include <bits/stdc++.h>
using namespace std;
#define ll int

const int mod = 1e9 + 7;

vector<ll> dp;

long long f(ll n) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    if (dp[n] != -1) return dp[n];

    long long ans = 0;
    if (n - 1 >= 0) {
        ans += (n - 1) * 1LL * f(n - 1); ans %= mod;
    }

    if (n - 2 >= 0) {
        ans += (n - 1) * 1LL * f(n - 2); ans %= mod;
    }

    return dp[n] = ans % mod;
}

int main() {
    ll n; cin >> n;
    dp.assign(n + 2, -1);

    cout << f(n);
}
