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

#define outin(v) for(auto &x:v)cin >> x
// #define deb(v) cout << #out<< " " << out << "\n"
// #define outout(v) for(auto x:v)cout << x << " " ;cout<<endl
// #define deb2(v, k) cout << #out<< " " << out << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

long long int M = mod;

ll binpow(ll a, ll b, ll MOD) {
    ll ans = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            ans = (ans * a) % MOD;
        b /= 2;
        a = (a * a) % MOD;
    }
    return ans;
}
ll inverse(ll a, ll MOD) {
    return binpow(a, MOD - 2, MOD);
}

ll dp[2][152][62][12][102][2];

ll f(ll turn, ll n, ll b, ll w, ll x, bool out) {
    if (n <= 0 && x <= 0) {
        return 1;
    }
    if (b == 0) return 0;
    if (out == true && x > 0) return 0;
    if (w == 0) return 0;
    if (dp[turn][n][b][w][x][out] != -1) return dp[turn][n][b][w][x][out];

    ll cnt = 0;
    if (b % 6 == 0 && out == false) {
        turn = 1 - turn;
    }

    if (turn && out == false) {
        cnt += f(0, n, b - 1 > 0 ? b - 1 : 0, w - 1, x, true); cnt %= mod;
        cnt += f(1 - turn, n - 1 > 0 ? n - 1 : 0, b - 1, w, x - 1 > 0 ? x - 1 : 0, out);cnt %= mod;
        cnt += f(1 - turn, n - 3 > 0 ? n - 3 : 0, b - 1, w, x - 3 > 0 ? x - 3 : 0, out);cnt %= mod;
        cnt += f(turn, n - 2 > 0 ? n - 2 : 0, b - 1, w, x - 2 > 0 ? x - 2 : 0, out);cnt %= mod;
        cnt += f(turn, n - 4 > 0 ? n - 4 : 0, b - 1, w, x - 4 > 0 ? x - 4 : 0, out);cnt %= mod;
        cnt += f(turn, n - 6 > 0 ? n - 6 : 0, b - 1, w, x - 6 > 0 ? x - 6 : 0, out);cnt %= mod;
    }

    else {
        cnt += f(turn, n, b - 1 > 0 ? b - 1 : 0, w - 1, x, out); cnt %= mod;
        cnt += f(out ? 1 - turn : 0, n - 1 > 0 ? n - 1 : 0, b - 1, w, x, out); cnt %= mod;
        cnt += f(out ? 1 - turn : 0, n - 3 > 0 ? n - 3 : 0, b - 1, w, x, out);cnt %= mod;
        cnt += f(turn, n - 2 > 0 ? n - 2 : 0, b - 1, w, x, out);cnt %= mod;
        cnt += f(turn, n - 4 > 0 ? n - 4 : 0, b - 1, w, x, out);cnt %= mod;
        cnt += f(turn, n - 6 > 0 ? n - 6 : 0, b - 1, w, x, out);cnt %= mod;
    }
    cnt %= mod;
    return dp[turn][n][b][w][x][out] = cnt;

}

void HHM() {
    ll  n, i, j, k, b, w, x;
    cin >> n >> b >> w >> x; w = 10 - w;
    x = 100 - x;

    memset(dp, -1, sizeof(dp));

    ll turn = 1;
    if (b % 6 == 0) {
        turn = 0;
    }

    ll q = inverse(6, mod);
    q = binpow(q, b, mod); q %= mod;
    ll p = f(turn, n, b, w, x, false);
    p %= mod;  p = (p * q) % mod;

    cout << p << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
