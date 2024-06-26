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
vector<ll>par;

void add(ll x, ll y) {
    par[x] = y; return;
}

ll findp(ll node) {
    while (par[node] != -1) {
        node = par[node];
    }
    return node;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<ll>v(n);
    vin(v); ll mx = *max_element(all(v));
    vector<ll>mp(mx + 1, 0); for (auto x : v) mp[x]++;

    for (i = 1; i <= mx; i++) {
        vector<ll>r;
        for (ll j = 0; j <= mx; j += i) {
            if (mp[j] > 0) {
                r.pb(j);
            }
        }
        if (r.size() > 1) {
            for (k = 1; k < r.size(); k++) {
                adj.pb({ r[0], r[k], i });
            }
        }
    }

    sort(all(adj), [&](vector<ll>& a, vector<ll>& b) {
        return a[2] > b[2];
        });

    par.assign(mx + 1, -1);

    for (auto x : adj) {
        if (findp(x[0]) != findp(x[1])) {
            ans += x[2];
            add(x[0], x[1]);
        }
    }

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}