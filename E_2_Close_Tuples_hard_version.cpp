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

const int N = 2e6 + 1;
const int MOD = 1000000007; // 998244353 
ll F[N], iF[N]; // Don't forget to change the value of N. factorial,Inverse Factorial Array
// if you want to use without any mod than mod will be INF 

ll fast(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    F[0] = 1;

    for (ll i = 1; i < N; ++i)
        F[i] = (F[i - 1] * i) % MOD;

    iF[N - 1] = fast(F[N - 1], MOD - 2);

    for (ll i = N - 2; i >= 0; --i)
        iF[i] = iF[i + 1] * (i + 1) % MOD;
}

ll NCR(ll n, ll r) {
    if (r > n || r < 0)
        return 0;

    return iF[r] * F[n] % MOD * iF[n - r] % MOD;
}

void HHM() {
    ll  n, i, j, k, m;
    cin >> n >> m >> k;

    vector<ll> v(n); vin(v);
    sort(all(v));


    ll prev = 1, ans = 0;

    for (i = 0; i < n; i++) {
        ll idx = upper_bound(all(v), v[i] + k) - v.begin();
        ll m1 = idx - i;

        if (idx - i >= m) {
            ll mn = min(prev - 1, m1);
            ans -= NCR(mn, m); ans %= MOD; ans += MOD; ans %= MOD;

            ans += NCR(m1, m); ans %= MOD; 
        }

        prev = m1;
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;

    init();

    while (t--) { HHM(); }
}
