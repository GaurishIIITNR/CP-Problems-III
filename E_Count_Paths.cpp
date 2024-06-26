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
long long int mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

vector<ll>ans;
ll res;

void dfs(vector<ll>* adj, ll node, ll& cnt, vector<bool>& vis, ll s) {
    vis[node] = 1; 
    for (auto x : adj[node]) {
        if (!vis[x] && s != x) {
            dfs(adj, x, cnt, vis, s);
        }
        else if (s == x) {
            cnt++;
        }
    }
    return;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<ll> v(n); vin(v);

    for (i = 0; i < n; i++) {
        ll d; cin >> d; pr.insert(d);
    }

    ans.assign(n + 1, 0);

    if (n == 1) {
        cout << 0 << endl; return;
    }

    vector<ll>adj[n + 1];
    res = 0;

    for (i = 0;i < n - 1;i++) {
        ll u, vv; cin >> u >> vv;
        adj[u].pb(vv); adj[vv].pb(u);
    }

    vector<bool>vis(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if(vis[i]) 
    }

    cout << res << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)  HHM();
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
