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

void dfs(vector<ll>*adj, ll src, ll par, vector<ll>&flat) {
    flat.push_back(src);
    for (auto x : adj[src]) {
        if (x != par) {
            dfs(adj, x, src, flat);
            flat.push_back(src);
        }
    }
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    vector<ll>adj[n + 1];
    for (i = 0;i < n - 1; i++) {
        ll u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    vector<ll>flat; dfs(adj, 1, 0, flat); vector<ll>st(n + 1, -1), en(n + 1, -1);
    for (i = 0;i < flat.size(); i++) {
        if (st[flat[i]] == -1) st[flat[i]] = i;
        else en[flat[i]] = i;
    }
    vector<ll> tmp(flat.size() + 1, 0);
    while (k--) {
        ll u, v; cin >> u >> v;
        // cout << u << " -- " << v << endl;
        ll l = st[u], l1 = en[u], r = st[v], r1 = en[v];
        // cout << l << " " << l1 << " " << r << " " << r1 << endl;
        if (l <= r && r1 <= l1) tmp[l]++, tmp[r + 1]--;
        else if (r <= l && l1 <= r1) tmp[r]++, tmp[l + 1]--;
        else if (l1 <= r) tmp[l1]++, tmp[r + 1]--;
        else if (r1 <= l) tmp[r1]++, tmp[l + 1]--;
    }
    ll sm = 0; vector<ll>ans(n + 1, 0);
    for (i = 0;i < flat.size(); i++) {
        sm += tmp[i]; ans[flat[i]] += 1;
    }
    for (i = 1; i <= n;i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
