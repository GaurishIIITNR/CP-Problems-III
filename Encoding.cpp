// हर हर महादेव
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

long long int mod = 1000000007;

#define f(a,b,c) dp[a][b][c]

int binpow(int a, int b) {
    long long int res = 1;
    while (b > 0) {

        if (b & 1)res = res * a; res %= mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return res % mod;
}

long long cal(string& a) {
    long long int ans = 0;
    for (int i = 0; i < a.size();i++) {
        if (!i)ans += (binpow(10, a.size() - i - 1) * ((a[i] - '0') % mod)) % mod;
        else if (a[i] == a[i - 1]) continue;
        else ans += (binpow(10, a.size() - i - 1) * (a[i] - '0')) % mod;
        ans %= mod;
    }
    return ans;
}

long long int solve(string a) {
    int dp[2][2][11];
    int cnt[2][2][11];
    for (int i = a.size(); i >= 0; i--) {
        for (int dt = 0; dt < 2; dt++) {
            for (int prev = 0; prev < 11; prev++) {
                if (i == a.size()) {
                    dp[i & 1][dt][prev] = 0;
                    cnt[i & 1][dt][prev] = 1;
                    continue;
                }

                int en = dt ? a[i] - '0' : 9;
                long long int ans = 0, cn = 0;

                for (int j = 0; j <= en; j++) {
                    long long int  r = dp[(i + 1) & 1][dt & (a[i] - '0' == j)][j];
                    long long int rr = cnt[(i + 1) & 1][dt & (a[i] - '0' == j)][j];
                    ans += r;
                    cn += rr;
                    ans %= mod;
                    if (j != prev) {
                        long long int res = binpow(10, (a.size() - i - 1)); res %= mod;
                        res *= (j % mod * rr % mod); res %= mod;
                        ans += res; ans %= mod;
                    }
                }
                dp[i & 1][dt][prev] = ans;
                cnt[i & 1][dt][prev] = cn;
            }
        }
    }
    return dp[0][1][10];
}

void HHM() {
    int  n, i, j, k;

    string a, b;
    cin >> n >> a;
    cin >> k >> b;

    long long int aa = solve(a);
    long long int bb = solve(b);

    cout << aa << " " << bb << "\n";
    long long int ans = (bb - aa + mod) % mod;
    ans += cal(a); ans %= mod;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
