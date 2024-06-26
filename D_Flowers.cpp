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
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

vector<ll> dp(1e5 + 5, 1);


void HHM() {
    ll  n, i, j, l, r;
    cin >> l >> r;

    ll ans = dp[r] - dp[l - 1];
    ans %= mod; ans += mod; ans %= mod;
    
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1, k;
    cin >> t >> k;

    for (ll i = 1; i < 1e5 + 4; i++) {
        dp[i] = dp[i - 1];
        if (i - k >= 0) dp[i] += dp[i - k];
        dp[i] %= mod;
    }

    dp[0] = 0;

    for (ll i = 1; i < 1e5 + 4; i++) {
        dp[i] += dp[i - 1]; dp[i] %= mod;
    }


    while (t--) { HHM(); }
}
