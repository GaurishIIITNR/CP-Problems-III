#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
bool vis[MAXN];
long long cnt;

void dfs(int u) {
    vis[u] = true;
    cnt++;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cnt = 0;
            dfs(i);
            ans = (ans * cnt) % 1000000007;
        }
    }
    cout << ans << endl;
    return 0;
}
