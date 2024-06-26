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

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

vector<vector<pair<ll, ll>>>adj;
vector<vector<ll>>dp;
// vector<ll>lev; vector<vector<ll>>vp;

void reset(ll n) {
    adj.assign(n + 1, vector<pair<ll, ll>>());
    dp.assign(n + 1, { 0, 0 });
}

vector<ll> dfs(ll src, ll par) {

    vector <ll> ans = { 0, -1 , -1 };
    for (auto x : adj[src]) {
        if (x.first != par) {
            auto y = dfs(x.first, src);
            ans[1] = max(ans[1], y[0] + x.second);
            if (y[1] == -1) {
                ans[2] = 0;
            }
            else if (y[2] == -1) {
                ans[2] = y[1] + x.second;
                ans[0] = 0;
            }
            else {
                ans[2] = y[1] + x.second;
                ans[0] = y[2] + x.second;
            } 
        }
    }
    dp[src] = ans;
    return ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    dp.assign(n + 1, { 0, 0 ,0 });
    adj.assign(n + 1, vector<pair<ll, ll>>());
    // lev.assign(n + 1, 0); vp.assign(n + 1, {});

    for (i = 0;i < n - 1;i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].pb({ v,w }); adj[v].pb({ u,w });
    }

    dfs(1, 0);
    for (i = 1; i <= n; i++) {
        vout(dp[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
