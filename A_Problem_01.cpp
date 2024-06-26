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

vector<ll> color;

bool dfs(vector<vector<ll>>& v, ll src, ll cnt) {
    if (cnt % 2 == 0) color[src] = 0;
    else color[src] = 1;

    bool ans = 1;

    for (auto x : v[src]) {
        if (color[x] == -1) {
            ans &= dfs(v, x, cnt + 1);
        }
        else if (color[x] == color[src]) return 0;
    }
    return ans;

}

void HHM() {
    ll  n, i, j, k, m;
    cin >> n >> m;
    color.assign(n + 1, -1);

    vector<vector<ll>>adj(n + 1,vector<ll>());

    for (ll i = 0; i < m;i++) {
        ll a, b; cin >> a >> b; adj[a].pb(b); adj[b].pb(a);
    }

    bool res = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) res &= dfs(adj, i, 0);
    }
    if (!res) {
        cout << "Suspicious bugs found!" << endl;
    }
    else {
        cout << "No suspicious bugs found!" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Scenario #" << i << ":" << endl;
        HHM();
    }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
