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

void dfs(vector<ll>* adj, ll src, ll par, vector<ll>& lev, ll cnt) {
    lev[src] = cnt; cnt++;
    for (auto x : adj[src]) {
        if (x != par) {
            dfs(adj, x, src, lev, cnt);
        }
    }
}

void HHM() {
    ll  n, i, j, k;
    cin >> n; vector<ll>adj[n + 1];
    for (i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector<ll>lev(n + 1, 0);
    ll leaf = 0, mx = 0; dfs(adj, 1, 0, lev, 0);
    for (i = 1; i <= n; i++) {
        if (mx < lev[i]) {
            mx = lev[i]; leaf = i;
        }
    }
    lev.clear(); lev.resize(n + 1, 0);
    dfs(adj, leaf, 0, lev, 0);
    ll leaf2 = 0; mx = 0;  for (i = 1; i <= n; i++) {
        if (mx < lev[i]) {
            mx = lev[i]; leaf2 = i;
        }
    }
    vector<ll>lev1(n + 1, 0);
    dfs(adj, leaf2, 0, lev1, 0);
    for (i = 1; i <= n; i++) {
        cout << max(lev[i], lev1[i]) << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
