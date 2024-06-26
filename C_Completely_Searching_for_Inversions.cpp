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
long long int mod = 998244353;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

bool f = 0;

void dfs(ll i, vector<pair<ll, ll>>* L, vector<ll>& S, ll& ans, ll& oc, ll par) {
    if (f) return;
    for (ll j = 0; j < S[i]; j++) {
        if (L[i][j].first == par) {
            f = 1; return;
        }
        if (L[i][j].second == 1)oc++;
        else  ans += oc; ans %= mod;
        dfs(L[i][j].first, L, S, ans, oc, i);

    }  return;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n; vector<pair<ll, ll>> L[n + 1];

    vector<ll>S(n + 1);

    for (i = 1;i <= n;i++) {
        cin >> S[i];
        for (j = 0;j < S[i];j++) {
            ll u, w; cin >> u >> w;
            L[i].pb({ u,w });
        }
    }

    ll ans = 0, oc = 0;
    dfs(1, L, S, ans, oc, 0);
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

