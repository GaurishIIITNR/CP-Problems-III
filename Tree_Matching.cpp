// // हर हर महादेव

// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define F first
// #define S second
// #define dbl double
// #define pb push_back
// #define ll long long int
// #define uset unordered_set
// #define umap unordered_map
// long long int mod = 1000000007;
// #define all(x) x.begin(), x.end()
// #define Pi 3.1415926535897932384626

// #define vin(v) for(auto &x:v)cin >> x
// #define deb(v) cout << #v << " " << v << "\n"
// #define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
// #define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

// typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

// ll ans = 0;

// void dfs(vector<ll>* adj, ll src, ll par, vector<bool>& vis) {
//     for (auto x : adj[src]) {
//         if (x != par) {
//             dfs(adj, x, src, vis);
//             if (!vis[x] && !vis[src]) vis[x] = vis[src] = 1, ans++;
//         }
//     }
// }

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n;   vector<ll> adj[n + 1];
//     for (i = 0;i < n - 1;i++) {
//         ll u, v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
//     }
//     vector<bool> vis(n + 1, 0);
//     dfs(adj, 1, 0, vis);
//     cout << ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     ll t = 1;
//     // cin >> t;
//     while (t--) { HHM(); }
// }
// // freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<ll>>adj;

vector<vector<ll>>dp;

void dfs(ll src, ll par) {
    // if (adj[src].size() == 1 && src != 1) {
    //     dp[src][0] = 0, dp[src][1] = 0; return;
    // }
    ll mx = 0;
    for (auto x : adj[src]) {
        if (x != par) {
            dfs(x, src);
            dp[src][0] += dp[x][1];
            mx = max(mx, dp[x][0] - dp[x][1] + 1);
        }
    }
    dp[src][1] += mx + dp[src][0];
    return;
}

int main() {
    ll n, i, j, k; cin >> n;
    adj.assign(n + 1, {});
    dp.assign(n + 1, vector<ll>(2, 0));

    for (i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);

    // for (i = 1; i < n + 1; i++) {
    //     cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    // }
    cout << max(dp[1][1], dp[1][0]) << endl;
}
