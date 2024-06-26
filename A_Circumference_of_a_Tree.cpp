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

class Graph {
    public:
    ll v, e; vector<vector<ll>>adj;

    // constructor
    Graph(ll v, ll e) {
        this->v = v;
        this->e = e;
        adj.resize(v + 1);
    }

    // take input
    void take() {
        for (ll i = 0; i < e; i++) {
            ll u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
    }

    // dfs
    void dfsTree(ll src, ll par, vector<ll>& depth) {
        depth[src] = depth[par] + 1;
        for (auto x : adj[src]) {
            if (x != par) {
                dfsTree(x, src, depth);
            }
        } return;
    }

    // bfs
    void bfsTree(ll src, vector<ll>& depth) {
        queue<ll>q; q.push(src); depth[src] = 0;
        while (!q.empty()) {
            ll node = q.front(); q.pop();
            for (auto x : adj[node]) {
                if (depth[x] == 0) {
                    depth[x] = depth[node] + 1;
                    q.push(x);
                }
            }
        } return;
    }
};



void HHM() {
    ll  n, i, j, k; cin >> n;
    Graph a(n, n - 1);
    a.take();
    vector<ll>depth(n + 1, 0);
    a.dfsTree(1, 0, depth);
    ll mx = 0, leaf = 0;
    for (i = 1; i < n + 1; i++) {
        if (depth[i] > mx) {
            mx = depth[i];
            leaf = i;
        }
    }

    depth.assign(n + 1, 0); a.dfsTree(leaf, 0, depth);
    mx = 0; for (i = 1; i <= n; i++) mx = max(mx, depth[i]);
    cout << 3 * (mx - 1) << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
