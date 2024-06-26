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

void BLift(vector<ll>* adj, vector<vector<ll>>& par, ll src, ll p, vector<ll>& lev) {
    par[src][0] = p;
    lev[src] = lev[p] + 1;

    for (ll i = 1;i < par[0].size(); i++) {
        par[src][i] = par[par[src][i - 1]][i - 1];
    }

    for (auto x : adj[src]) {
        if (x != p)  BLift(adj, par, x, src, lev);
    }  return;
}

ll KthPar(vector<vector<ll>>& par, ll node, ll k) {
    ll i = 0; while (k) {
        if (k & 1) node = par[node][i];
        k >>= 1; i++;
    } return node;
}

ll lca(vector<vector<ll>>& par, ll u, ll v, vector<ll>& dep) {

    if (dep[u] > dep[v]) u = KthPar(par, u, dep[u] - dep[v]);
    else if (dep[v] > dep[u]) v = KthPar(par, v, dep[v] - dep[u]);
    if (u == v) return u;

    for (ll i = par[0].size() - 1;i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }

    return par[u][0];
}

void HHM() {
    ll  n, i, j, q;

    cin >> n >> q; vector<ll>adj[n + 1];
    for (i = 2; i <= n;i++) {
        ll x; cin >> x; adj[x].push_back(i); adj[i].push_back(x);
    }

    vector<vector<ll>>par(n + 1, vector<ll>((ll)(log2(n) + 2), 0));
    vector<ll>lev(n + 1, 0); BLift(adj, par, 1, 0, lev);


    while (q--) {
        ll u, v; cin >> u >> v;
        cout << lca(par, u, v, lev) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}

// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
