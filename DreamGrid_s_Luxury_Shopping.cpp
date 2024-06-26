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

// bool req(vector<ll>& v, ll m, ll k) {
//     ll cnt = 0;
//     for (auto x : v) {
//         if (m >= x) cnt++, m -= x;
//         else continue;
//     }
//     return cnt <= k;
// }

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k; vector<ll>v(n); vin(v);

    ll ans = 0;
    for (i = 0; i < k; i++) ans += v[i];

    ll mn = INT_MAX;
    for (i = k; i < n; i++) mn = min(mn, v[i]);
    if (mn != INT_MAX) ans += mn - 1;

    // ll l = 0, h = 1e15;
    // while (l < h) {
    //     ll m = l + (h - l + 1) / 2;
    //     if (req(v, m, k)) l = m;
    //     else h = m - 1;
    // }

    // ans = max(ans, l);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
