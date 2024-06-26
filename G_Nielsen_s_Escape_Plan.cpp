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


ll dp[102][2][16][16][2];

ll f(string& a, int i, bool t, ll xr, ll ad, bool z, string s) {

    if (i == a.size()) {
        if (xr > ad) return 1;
        return  0;
    }

    if (dp[i][t][xr][ad][z] != -1)return dp[i][t][xr][ad][z];
    int end = (t ? a[i] - '0' : 9);

    ll ans = 0;

    for (int j = 0; j <= end; j++) {
        if (z == 1 && j == 0) {
            ans += f(a, i + 1, (t & (j == end)), (xr ^ j), ad, 1, s + to_string(j));
        }
        else {
            ans += f(a, i + 1, (t & (j == end)), (xr ^ j), (ad & j), (z & (j == 0)), s + to_string(j));
        }
        ans %= mod;
    }

    return dp[i][t][xr][ad][z] = ans % mod;
}



void HHM() {
    memset(dp, -1, sizeof(dp));

    string l, r; cin >> l >> r;
    ll ans = f(r, 0, 1, 0, 15, 1, "");

    cout << endl;
    // memset(dp, -1, sizeof(dp));
    // ans -= f(l, 0, 1, 0, 15, 1);

    // ll ad = 15, xr = 0;
    // for (auto& x : l) {
    //     ll ch = x - '0';
    //     ad &= ch; xr ^= ch;
    // }

    // if (xr > ad)ans++; ans %= mod;
    // cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
