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

void blift(vector<ll>* adj, vector<vector<ll>>& par, vector<ll>& lev, ll src, ll p) {
    par[src][0] = p; lev[src] = lev[p] + 1;
    for (ll i = 1; i < par[0].size(); i++) {
        par[src][i] = par[par[src][i - 1]][i - 1];
    }
    for (auto x : adj[src]) {
        if (x != p) blift(adj, par, lev, x, src);
    } return;
}

ll parent(ll node, ll k, vector<vector<ll>>& par) {
    ll i = 0;
    while (k) {
        if (k & 1) node = par[node][i];
        k >>= 1; i++;
    } return node;
}

ll lca(ll u, ll v, vector<vector<ll>>& par, vector<ll>& dep) {
    if (dep[u] > dep[v]) swap(u, v);
    v = parent(v, dep[v] - dep[u], par);

    if (u == v) return u;

    for (ll i = par[0].size() - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }
    return par[u][0];
}

void HHM() {
    ll  n, i, j, q;
    cin >> n >> q; vector<ll>adj[n + 1];
    for (i = 0;i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    ll logn = (ll)(log2(n) + 2);
    vector<vector<ll>>par(n + 1, vector<ll>(logn, 0));
    vector<ll>lev(n + 1, 0); blift(adj, par, lev, 1, 0);

    while (q--) {
        ll u, v; cin >> u >> v; ll l = lca(u, v, par, lev);
        ll ans = lev[u] - lev[l] + lev[v] - lev[l];
        cout << ans << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
