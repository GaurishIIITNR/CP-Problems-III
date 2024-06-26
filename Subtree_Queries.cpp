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

ll q(vector<ll>& BIT, ll i) {
    ll sm = 0;
    for (ll j = i; j > 0; j -= j & (-j))  sm += BIT[j];
    return sm;
}

void up(vector<ll>& BIT, ll i, ll x, ll val) {
    for (ll j = i; j < BIT.size(); j += (j & (-j))) BIT[j] -= val, BIT[j] += x;
}

void dfs(ll src, vector<ll>* adj, ll p, vector<ll>& flat) {
    flat.pb(src);
    for (auto x : adj[src]) if (x != p) dfs(x, adj, src, flat);
    flat.pb(src);
    return;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    vector<ll>v(n + 1, 0);

    for (i = 1; i <= n; i++)cin >> v[i];
    vector<ll>adj[n + 1], flat, BIT;

    for (i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b; adj[a].pb(b); adj[b].pb(a);
    }    dfs(1, adj, 0, flat);

    BIT.resize(flat.size() + 1, 0);
    for (i = 0;i < flat.size();i++) {
        up(BIT, i + 1, v[flat[i]], 0);
    }
    // vout(flat);
    // vout(BIT);

    map<ll, pair<ll, ll>>mp;
    for (i = 0;i < flat.size();i++) {
        if (mp.find(flat[i]) == mp.end())mp[flat[i]] = { i + 1, i + 1 };
        else mp[flat[i]].S = i + 1;
    }

    while (k--) {
        ll x; cin >> x;
        if (x == 1) {
            ll a, val; cin >> a >> val;
            ll f = mp[a].F, s = mp[a].S;
            up(BIT, f, val, v[a]); up(BIT, s, val, v[a]); v[a] = val;
        }
        else {
            ll a; cin >> a;
            cout << (q(BIT, mp[a].S) - q(BIT, mp[a].F - 1)) / 2 << "\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
