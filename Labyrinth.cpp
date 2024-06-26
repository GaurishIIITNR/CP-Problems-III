/*
    Problem  : Labyrinth
    URL      : https://cses.fi/problemset/task/1193
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

int main() {
    ll n, m; cin >> n >> m;
    vector<string>v(n);
    
    ll sti, stj, eni, enj;
    
    for (ll i = 0;i < n; i++) {
        cin >> v[i];
        for (ll j = 0; j < m; j++) {
            if (v[i][j] == 'A') sti = i, stj = j;
            else if (v[i][j] == 'B') eni = i, enj = j;
        }
    }
    
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    vector<vector<int>>par(n, vector<int>(m));
    
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    char dir[4] = { 'U', 'R', 'D', 'L' };
    
    queue<pair<ll, ll>>q; q.push({ sti, stj });
    vis[sti][stj] = true; bool ans = 0;
    
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        
        if (top.first == eni && top.second == enj) {
            ans = 1; break;
        }
        
        for (int r = 0; r < 4; r++) {
            ll x = top.first + dx[r], y = top.second + dy[r];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && v[x][y] != '#') {
                vis[x][y] = true;
                par[x][y] = r;
                q.push({ x, y });
            }
        }
        
    }
    
    if (!ans) {
        cout << "NO\n"; return 0;
    }
    
    cout << "YES\n";
    string res = "";
    
    while (eni != sti || enj != stj) {
        res += dir[par[eni][enj]];
        int r = par[eni][enj];
        eni -= dx[r]; enj -= dy[r];
    }
    
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    cout << res << endl;
 
 
}
