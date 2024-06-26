#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<int> calDis(vector<int>* adj, int s, int n) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> ed(n);
        for (auto& x : ed) cin >> x;

        int s, d;
        cin >> s >> d;

        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            if (ed[i] != -1) {
                adj[i].push_back(ed[i]);
            }
        }

        vector<int> dis1 = calDis(adj, s, n), dis2 = calDis(adj, d, n);

        int mn = INT_MAX, ans = -1;

        for (int i = 0; i < n; i++) {
            if (dis1[i] == INT_MAX || dis2[i] == INT_MAX) continue;
            if (dis1[i] + dis2[i] < mn) {
                mn = dis1[i] + dis2[i]; ans = i;
            }
        }

        cout << ans << endl;
    }


    map<int, int> mp;


    return 0;
}