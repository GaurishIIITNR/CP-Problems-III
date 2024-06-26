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
    ll  n, i, j, k;
    cin >> n >> k >> j;
    vector<pair<ll, ll>>vp;
    for (i = 0; i < k; i++) {
        ll x, y; cin >> x >> y;
        vp.pb({ x, y });
    }

    sort(all(vp), [&](pair<ll, ll>& a, pair<ll, ll>& b) {
        if (a.F == b.F) return a.S < b.S;
        return a.F < b.F;
        });

    ll ans = 0;
    if (k <= 2) {
        cout << n << endl; return;
    }

    ll freefund = vp[0].F - 1 > 0 ? vp[0].F - 1 : 0;

    ll mx = 0;
    for (i = 0; i < k - 1; i++) {
        mx = max(mx, vp[i].S);
        freefund += vp[i + 1].F - mx > 0 ? vp[i + 1].F - mx : 0;
    }
    freefund += n - mx > 0 ? n - mx : 0;
    cout << freefund << endl;
    // reverse(all(vp));
    // for (i = 0; i < k - 3; i++) {
    //     cout << vp[i].F << " " << vp[i].S << endl;
    //     cout << vp[i + 2].F << " " << vp[i + 2].S << endl;
    //     cout << endl;
    //     ll cnt = vp[i + 2].F - vp[i].F;
    //     cnt += vp[i].S > vp[i + 2].S ? (vp[i].S - vp[i + 2].S) : 0;
    //     ans = max(ans, cnt);
    // }

    // cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
