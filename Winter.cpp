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

vector<vector<ll>>adj;
vector<ll>vis;
queue<ll>q;


void HHM() {
    ll  n, i, j, k, m;
    cin >> n >> m >> k;

    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, 0);

    for (i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);  adj[y].pb(x);
    }

    while (k--) {
        ll x, y; cin >> x >> y;

        if (x == 1) {
            if (vis[y] == 0) {
                q.push(y);
                vis[y] = 1;
            }
        }
        else if (x == 3) {
            if (vis[y]) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            for (i = 0; i < y; i++) {
                queue<ll>temp;
                while (q.size()) {
                    ll u = q.front();
                    q.pop();
                    for (auto v : adj[u]) {
                        if (vis[v] == 0) {
                            vis[v] = 1;
                            temp.push(v);
                        }
                    }
                }

                if (temp.size() == 0) break;
                q = temp;
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
