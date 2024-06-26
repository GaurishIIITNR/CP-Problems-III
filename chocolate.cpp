// हर हर महादेव 
// Author: Gaurish Ojha

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<pair<int, int>>> g;
vector<vector<pair<int, int>>>_g;

int dij(int src, int dest) {
    vector<int> dist(_g.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({ 0, src });

    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();

        for (auto x : _g[u]) {
            auto [v, w] = x;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist[dest];
}

int main() {
    int n; cin >> n; // number of vertices

    g.assign(n + 1, vector<pair<int, int>>()); // given graph

    int m; cin >> m; // number of edges

    for (int i = 0;i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({ v, w }); // directed and weighted 
    }

    int src, dest; cin >> src >> dest; // source and destination
    int k; cin >> k; // atmost no of edge weight changes allowed

    _g.assign((n * (k + 1)) + 2, vector<pair<int, int>>()); // modified graph

    for (int i = 1; i <= n; i++) {
        for (auto x : g[i]) {
            for (int j = 0; j <= k; j++) {
                _g[i + (j * n)].push_back({ x.first + (j * n), x.second });

                if (j + 1 <= k) {
                    _g[i + (j * n)].push_back({ x.first + ((j + 1) * n), 0 });
                }
            }
        }
    }

    // add start fake node as 0
    for (int i = 0; i <= k; i++) {
        _g[0].push_back({ (i * n) + src, 0 });
    }

    // add end fake node as (n*(k + 1)) + 1

    for (int i = 0; i <= k; i++) {
        _g[dest + (i * n)].push_back({ (n * (k + 1)) + 1, 0 });
    }

    cout << dij(0, (n * (k + 1)) + 1);

    return 0;
}

