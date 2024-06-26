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

ll ans = 0;


ll f(vector<ll>& v, ll& tot) {

    vector<vector<ll>>dp(2, vector<ll>(tot, 0));

    for (ll i = v.size(); i >= 0; i--) {
        for (ll sm = 0; sm <= tot; sm++) {

            if (i == v.size()) {
                dp[i & 1][sm] = abs((tot - sm) - sm); continue;
            }

            ll mn = tot;
            mn = min(mn, dp[(i + 1) & 1][sm + v[i]]);
            mn = min(mn, dp[(i + 1) & 1][sm]);
            dp[i & 1][sm] = mn;
        }
    }

    return dp[0][0];
}

ll dfs(vector<ll>* adj, ll src) {
    ll tot = 0;
    if (adj[src].size() == 0) return 1;

    vector<ll>tmp;

    for (auto x : adj[src]) {
        tmp.pb(dfs(adj, x));
        if (tmp.size()) tot += tmp.back();
    }

    if (tmp.size()) {
        ll diff = f(tmp, tot);
        ll x = (tot + diff) / 2;
        ans += x * (tot - x);
    }

    return tot + 1;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<ll>adj[n + 1];
    for (i = 2; i <= n; i++) {
        ll x; cin >> x;
        adj[x].pb(i);
    }

    dfs(adj, 1);
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
