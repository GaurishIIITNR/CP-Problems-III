/*
    Problem  : Building Roads
    URL      : https://cses.fi/problemset/task/1666
    Author   : Gaurish Ojha (211020418)
    Platform : CSES
*/


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


int dfs(vector<int>*adj, int curr, vector<bool>&vis) {
    vis[curr] = true;
    for (auto x : adj[curr]) {
        if (!vis[x]) {
            dfs(adj, x, vis);
        }
    }
    return curr;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m;i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n + 1, false);
    vector<int>res;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res.push_back(dfs(adj, i, vis));
        }
    }
    cout << res.size() - 1 << endl;
    for (int i = 1; i < res.size();i++) {
        cout << res[i - 1] << " " << res[i] << endl;
    }
}
