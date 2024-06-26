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

#define vin(v) for(auto &z: v)cin >> z
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

map<pair<ll, ll>, ll> dis;

ll dfs(vector<pair<ll, ll>>* adj, ll s, vector<bool>& vis, ll col, ll& d) {
    vis[s] = 1;
    ll ans = INT_MAX;

    if (s == d) {
        return dis[{s, col}] = 0;
    }
    for (auto x : adj[s]) {
        if (vis[x.F] == 1) {
            ans = min((col != x.S) + dis[{}, ans); continue;
        }
        else ans = min(ans, (col != x.S) + dfs(adj, x.F, vis, x.S, d));
    }

    return dis[{s, col}] = ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    dp.clear();

    vector<pair<ll, ll>> adj[n];

    for (i = 0; i < k; i++) {
        ll u, v, w;
        cin >> u >> v >> w; --u; --v;
        adj[u].pb({ v, w });
        adj[v].pb({ u, w });
    }

    ll s, d; cin >> s >> d;
    --s, --d;

    vector<bool> vis(n, 0);
    vector<ll> dis(n, INT_MAX);

    cout << dfs(adj, s, vis, -1, d) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}



class Solution {
    public:
    int strStr(string s, string p) {
        vector<int> lps(p.size(), 0);

        for (int i = 1; i < p.size(); i++) {
            int k = lps[i - 1];

            while (k > 0 && p[k] != p[i]) {
                k = lps[k - 1];
            }

            if (p[k] == p[i]) {
                lps[i] = ++k;
            }
        }

        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            while (k > 0 && p[k] != s[i]) {
                k = lps[k - 1];
            }

            if (s[i] == p[k]) {
                k++;
                if (k == p.size()) {
                    return i - p.size() + 1;
                }
            }
        }

        return -1;
    }
};