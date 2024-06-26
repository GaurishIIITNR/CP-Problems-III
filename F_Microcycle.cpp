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

class DSU {
    public:
    vector<ll>par, rank;
    ll n;

    DSU(ll n) {
        this->n = n;
        par.assign(n + 1, -1);
        // sz.assign(n + 1, 1);
        rank.assign(n + 1, 0);
    }

    ll findPar(ll node) {
        if (par[node] == -1) return node;
        // used path compression
        return par[node] = findPar(par[node]);
    }

    void UnionByRank(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;
        if (rank[pu] == rank[pv]) {
            rank[pu]++; par[pv] = pu;
        }
        else if (rank[pu] > rank[pv])par[pv] = pu;
        else par[pu] = pv;    return;
    }

};

vector<ll>res;

bool dfs(vector<ll>* adj, ll src, ll par, vector<bool>& vis) {
    vis[src] = true;
    ll val = -1;
    bool ans = false;

    for (auto x : adj[src]) {
        if (x == par)continue;
        if (vis[x]) {
            return true;
        }
        if (dfs(adj, x, src, vis)) {
            res.pb(x);
            return true;
        }
    }

    return ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    vector<vector<ll>>v(k, vector<ll>(3));
    res.clear();

    for (i = 0; i < k; i++) {
        cin >> v[i][1] >> v[i][2] >> v[i][0];
    }

    sort(all(v), greater<vector<ll>>());

    DSU d(n);
    vector<ll>adj[n + 1];
    vector<bool>vis(n + 1, 0);


    ll x = -1, y = -1, ans = INT_MAX;

    for (i = 0; i < k; i++) {
        ll u = v[i][1], vv = v[i][2], w = v[i][0];
        if (d.findPar(u) == d.findPar(vv)) {
            x = u, y = vv;
            ans = min(ans, w);
        }
        else {
            adj[u].pb(vv); adj[vv].pb(u);
            d.UnionByRank(u, vv);
        }
    }

    d.UnionByRank(x, y);
    adj[x].pb(y); adj[y].pb(x);

    dfs(adj, x, y, vis); res.pb(x);

    cout << ans << " " << res.size() << "\n";
    vout(res);

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
