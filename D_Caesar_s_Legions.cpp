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
long long int mod = 1e8;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &z: v)cin >> z
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

ll tot, k1, k2, n, m;
ll dp[202][102][12][4];

ll f(ll curr, ll hm, ll succ, ll t) {

    if (curr == tot) {
        return 1;
    }

    if (dp[curr][hm][succ][t] != -1) return dp[curr][hm][succ][t];

    ll remhm = m - hm;
    ll remm = n - (curr - hm);


    ll ans = 0;

    if (t == 2) {
        if (remhm) ans += f(curr + 1, hm + 1, succ + 1, 1); ans %= mod;
        if (remm) ans += f(curr + 1, hm, succ + 1, 0); ans %= mod;
    }
    else if (t == 0) {
        if (remhm)  ans += f(curr + 1, hm + 1, 1, 1); ans %= mod;
        if (succ + 1 <= k1 && remm) {
            ans += f(curr + 1, hm, succ + 1, 0); ans %= mod;
        }
    }
    else {
        if (remm) ans += f(curr + 1, hm, 1, 0); ans %= mod;
        if (succ + 1 <= k2 && remhm) {
            ans += f(curr + 1, hm + 1, succ + 1, 1); ans %= mod;
        }
    }

    return dp[curr][hm][succ][t] = ans % mod;

}

void HHM() {
    ll  i, j, k;
    cin >> n >> m >> k1 >> k2;
    tot = n + m;

    memset(dp, -1, sizeof(dp));

    cout << f(0, 0, 0, 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
