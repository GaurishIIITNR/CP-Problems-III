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

void HHM() {
    ll  n, i, j, k, h;
    cin >> n >> k >> h;
    vector<pair<ll, ll>>v(n + 1), ans(n + 1);
    for (i = 1; i <= n; i++) {
        cin >> v[i].first; v[i].second = 0;
    }  ans = v;

    vector<ll>adj[n + 1];
    priority_queue< ll, vector<ll>, greater<ll>>pq;

    vector<ll> deg(n + 1, 0);

    for (i = 0;i < k;i++) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b); deg[b]++;
    }

    for (i = 1;i <= n; i++) {
        if (deg[i] == 0) pq.push(i);
    }

    while (pq.size()) {
        ll node = pq.top(); pq.pop();
        ll dg = deg[node];
        // mx = max(mx, ans[node].first + (h * ans[node].second));
        // cout << node << " " << ans[node].first << " " << ans[node].second << endl;

        for (auto x : adj[node]) {
            deg[x]--;
            // cout << "  " << x << " " << ans[x].first << " " << ans[x].second << endl;
            if (ans[x].second == ans[node].second) {
                if (ans[x].first < ans[node].first) {
                    ans[x].second++; ans[x].first = v[x].first;
                }
            }

            else if (ans[x].second < ans[node].second) {
                if (v[x].first >= ans[node].first) ans[x].second = ans[node].second;
                else ans[x].second = ans[node].second + 1, ans[x].first = v[x].first;
            }

            if (deg[x] == 0) pq.push(x);
        }
    }
    vector<ll>res;
    for (i = 1; i <= n;i++) {
        res.pb(ans[i].first + (h * ans[i].second));
    }
    ll minv = INT_MAX;
    for (auto x : res) minv = min(minv, x)


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
