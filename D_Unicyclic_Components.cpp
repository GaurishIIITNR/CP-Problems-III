// Gaurish Ojha(211020418)

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

void dfs(vector<ll>* adj, ll src, vector<bool>& vis, ll& cnt, ll& val) {
    vis[src] = 1; //val += mp[{src, src}]; 
    cnt++;
    for (auto x : adj[src]) {
        if (!vis[x]) {
            val++;//= mp[{min(x, src), max(x, src)}];
            dfs(adj, x, vis, cnt, val);
        }
        else val++;
    } return;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    vector<ll>adj[n + 1];

    for (i = 0; i < k;i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vector<bool>vis(n + 1, 0);
    bool ans = 1;
    for (i = 1; i <= n;i++) {
        if (vis[i]) continue;
        ll cnt = 0, val = 0;
        dfs(adj, i, vis, cnt, val);
        // cout << i << " ";
        // cout << cnt << " " << val << endl;
        ans &= (2 * cnt == val);
    }
    if (ans) {
        cout << "Yes\n"; return;
    }
    cout << "No\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++)  HHM();
}