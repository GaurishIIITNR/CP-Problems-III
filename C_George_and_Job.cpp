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
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

ll f(ll i, ll rem, ll& m, vector<ll>& v, ll sm) {

    if (i == v.size()) {
        // cout << sm << " " << rem << endl;
        if (rem == 0)  return 0;
        return INT_MIN;
    }

    ll ans = 0;

    if (rem > 0) {
        ans = max(ans, f(i + 1, rem - 1, m, v, sm));
    }

    if (i + m - 1 < v.size()) {
        ll val = v[i + m - 1] - ((i == 0) ? 0 : v[i - 1]);
        ans = max(ans, f(i + m, rem, m, v, sm + val) + val);
    }

    return ans;
}

void HHM() {
    ll m, n, i, j, k;
    cin >> n >> m >> k;

    vector<ll> v(n); vin(v);

    for (i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }

    // vout(v);

    ll rem = n - (k * m);
    cout << f(0, rem, m, v, 0) << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);

    ll t = 1;
    while (t--) { HHM(); }
}
