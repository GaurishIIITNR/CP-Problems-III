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
#define ll int
#define uset unordered_set
#define umap unordered_map
long long int mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;


ll f(ll l, ll r, vector<ll>& v, ll h) {
    vector<vector<ll>>dp(2, vector<ll>(h, 0));
    for (int i = v.size(); i >= 0;i--) {
        for (int curr = h - 1; curr >= 0; curr--) {
            if (i == v.size()) {
                dp[i & 1][curr] = 0; continue;
            }
            ll tt = curr + v[i]; tt %= h;
            ll ans = (tt >= l && tt <= r) + dp[(i + 1) & 1][tt];
            tt = curr + v[i] - 1; tt %= h;
            ans = max(ans, (tt >= l && tt <= r) + dp[(i + 1) & 1][tt]);
            dp[i & 1][curr] = ans;
        }
    }
    return dp[0][0];
}

void HHM() {
    ll  n, i, j, k, h, l, r;
    cin >> n >> h >> l >> r;
    vector<ll>v(n); vin(v);
    cout << f(l, r, v, h) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
