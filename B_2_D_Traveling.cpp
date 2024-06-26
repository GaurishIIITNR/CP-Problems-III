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

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n;  

// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     ll t = 1;
//     cin >> t;
//     while(t--){ HHM(); }
// }
// // freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
#define ll long long 



class lift {
    public:

    vector<vector<ll>>adj, par;
    vector<ll> lev; ll n, logn;

    // n is the number of nodes in the tree
    lift(ll sz) {
        n = sz; logn = log2(n) + 2;
        adj.assign(n + 1, {});
        par.assign(n + 1, vector<ll>(logn, 0));
        lev.assign(n + 1, 0);
    }

    //taking input of the tree
    void takeInput() {
        for (ll i = 1;i < n; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
    }

    //filling the parent array of the tree
    void BLift(ll src, ll p) {
        par[src][0] = p;
        lev[src] = lev[p] + 1;

        for (ll i = 1;i < par[0].size(); i++) {
            par[src][i] = par[par[src][i - 1]][i - 1];
        }

        for (auto x : adj[src]) {
            if (x != p)  BLift(x, src);
        }  return;
    }

    //K-the parent of a node
    ll KthPar(ll node, ll k) {
        ll i = 0; while (k) {
            if (k & 1) node = par[node][i];
            k >>= 1; i++;
        } return node;
    }

    //finding the lca of two nodes
    ll lca(ll u, ll v) {
        if (lev[u] > lev[v]) u = KthPar(u, lev[u] - lev[v]);
        else if (lev[v] > lev[u]) v = KthPar(v, lev[v] - lev[u]);
        if (u == v) return u;

        for (ll i = par[0].size() - 1;i >= 0; i--) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i]; v = par[v][i];
            }
        }
        return par[u][0];
    }
};


int main() {
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;

    }
    return 0;
}