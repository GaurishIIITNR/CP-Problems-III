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

#define vin(v) for(auto &z: v)cin >> z
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

vector<vector<ll>>adj, par;
vector<ll>lev, ans, final_ans;

void reset(ll n) {
    adj.assign(n + 1, {});
    par.assign(n + 1, vector<ll>(20, 0));
    lev.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    final_ans.assign(n + 1, 0);
}

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

ll KthPar(ll node, ll k) {
    ll i = 0; while (k) {
        if (k & 1) node = par[node][i];
        k >>= 1; i++;
    } return node;
}

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

ll dfs(ll src, ll p) {
    ll res = 0;

    for (auto x : adj[src]) {
        if (x != p) {
            res += dfs(x, src);
        }
    }

    res += ans[src];
    final_ans[src] = res;

    return res;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    reset(n);

    for (i = 0;i < n - 1;i++) {
        ll uu, vv; cin >> uu >> vv;
        adj[uu].pb(vv); adj[vv].pb(uu);
    }

    BLift(1, 0);

    for (i = 1;i < n; i++) {
        ll lc = lca(i, i + 1);

        if (lc == i) {
            ans[lc]--; ans[i + 1]++;
        }
        else if (lc == i + 1) {
            ans[KthPar(lc, 1)]--; ans[KthPar(i, 1)]++;
        }
        else {
            ans[KthPar(i, 1)]++; ans[i + 1]++; ans[KthPar(lc, 1)]--; ans[lc]--;
        }
    }

    // vout(ans);


    dfs(1, 0);

    final_ans[1]++;
    for (i = 1;i <= n; i++) cout << final_ans[i] << " "; cout << endl;


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
