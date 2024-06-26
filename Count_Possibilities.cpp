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

vector<vector<ll>> adj;
vector<bool>vis;
vector<ll>v, ans, mx;

void reset(ll n) {
    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);
    v.assign(n + 1, 0); mx.assign(n + 1, 0);
    ans.assign(n + 1, 0);
}



void HHM() {
    ll  n, i, j, k;
    cin >> n;
    reset(n);
    vector<pair<ll, ll>>vp;
    
    for (i = 0; i < n - 1;i++) {
        ll u, vv;cin >> u >> vv;
        vp.pb({ u,vv });
        adj[vv].pb(u); v[u]++;
    }

    queue<ll>q;
    for (i = 1;i <= n;i++) {
        if (v[i] == 0) {
            q.push(i);
        }
    }
    for (i = 1;i <= n;i++) {
        if (v[i] == 0) {
            q.push(i); vis[i] = true;
        }
    }

    while (q.size()) {
        ll u = q.front(); q.pop();
        for (auto x : adj[u]) {
            v[x] += v[u];
            if (!vis[x]) {
                q.push(x);
                vis[x] = true;
            }
        }
    }
    
    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);
    
    for (auto x : vp) {
        adj[x.first].pb(x.second);
        mx[x.second]++;
    }
    for (i = 1;i <= n;i++) {
        if (mx[i] == 0) {
            q.push(i); vis[i] = true;
        }
    }
    while (q.size()) {
        ll u = q.front(); q.pop();
        for (auto x : adj[u]) {
            mx[x] += mx[u];
            if (!vis[x]) {
                q.push(x);
                vis[x] = true;
            }
        }
    }

    // vout(mx);

    for (i = 1; i <= n; i++) {
        ans[n - v[i]]--;
        ans[mx[i]]++;
    }

    // vout(ans);
    for (i = 0; i < n;i++) {
        if (i != 0) ans[i] += ans[i - 1];
    }
    for (i = 0; i < n;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
