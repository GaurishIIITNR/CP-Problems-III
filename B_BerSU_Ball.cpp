#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll n, m;
vector<ll> a, b;
vector<vector<ll>> dp;

ll f(ll i, ll j) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll ans = f(i + 1, j);
    ans = max(ans, f(i, j + 1));

    if (abs(a[i] - b[j]) <= 1) {
        ans = max(ans, 1 + f(i + 1, j + 1));
    }

    return dp[i][j] = ans;
}

int main() {

    cin >> n;
    a.assign(n, 0);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());

    cin >> m;
    b.assign(m, 0);
    for (auto& x : b) cin >> x;
    sort(b.begin(), b.end());

    dp.assign(n + 1, vector<ll>(m + 1, -1));
    cout << f(0, 0);


    return 0;
}
