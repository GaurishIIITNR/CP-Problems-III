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


ll xrr(ll r) {
    ll res = 0;
    if (r % 4 == 0) {
        res = r;
    }
    else if (r % 4 == 1) {
        res = r ^ (r - 1);
    }
    else if (r % 4 == 2) {
        res = r ^ (r - 1) ^ (r - 2);
    }

    return res;
}

ll xr(ll l, ll r) {
    ll ans = 0;
    if (l - 1 >= 0)ans ^= xrr(l - 1);
    return  ans ^ xrr(r);
}

void HHM() {
    ll  n, i, j, k, m, x, y;
    cin >> n >> m >> x >> y; --x, --y;

    ll minX = min(x, n - x - 1);
    ll minY = min(y, m - y - 1);

    ll ans = xr((minX + 1), n - x - 1);
    ans ^= xr((minY + 1), m - y - 1);
    ans ^= xr((minX + 1) + (minY + 1), n - x - 1 + m - y - 1);


    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
