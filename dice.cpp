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


ll f(vector<pair<ll, ll>>* adj, ll src, ll dest, ll n) {
    vector<ll> dis(n, INT_MAX);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0, src });

    dis[src] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        for (auto& e : adj[u]) {
            ll v = e.first;
            ll w = e.second;

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({ dis[v], v });
            }
        }
    }

    return dis[dest];
}

void HHM() {
    ll n; cin >> n;
    ll i, j, k;

    // map id b/w (0, n - 1)
    map<ll, ll> mp;

    for (i = 0;i < n; i++) {
        ll x; cin >> x;
        mp[x] = i;
    }

    ll e; cin >> e;

    vector<pair<ll, ll>>adj[n];

    for (i = 0;i < e; i++) {
        ll u, v, t; cin >> u >> v >> t;
        u = mp[u]; v = mp[v];
        adj[u].pb({ v, t });
    }

    ll u, v; cin >> u >> v;

    u = mp[u]; v = mp[v];

    ll ans = f(adj, u, v, n);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}