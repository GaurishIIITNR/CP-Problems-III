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

vector<vector<ll>>dp;
ll f(vector<pair<ll, ll>>& v, ll i, ll mex) {

    if (i == v.size() - 1) {
        return ((v[i].second - 1) * mex) + v[i].first;
    }
    if (dp[i][mex] != -1) return dp[i][mex];

    ll ans = f(v, i + 1, mex);
    ans = min(ans, ((v[i].second - 1) * mex) + v[i].first + f(v, i + 1, v[i].first));
    return dp[i][mex] = ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n; map<ll, ll>mp;
    for (i = 0; i < n; i++) {
        ll x; cin >> x; mp[x]++;
    }
    vector<pair<ll, ll>>v;

    ll prev = -1;
    for (auto x : mp) {
        if (x.first - 1 != prev) break;
        v.pb({ x.first, x.second }); prev++;
    }

    prev++;
    if (prev == 0) {
        cout << 0 << endl; return;
    }
    dp.assign(v.size() + 1, vector<ll>(prev + 1, -1));
    sort(all(v)); reverse(all(v));
    cout << f(v, 0, prev) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
