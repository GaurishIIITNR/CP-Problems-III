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

void HHM() {
    ll  n, i, j, k, mx;
    cin >> n >> mx >> k;

    vector<ll> v(n); vin(v);

    vector<ll> p = v; sort(all(p));
    map<ll, ll> mp;

    ll r = k + mx - 1; r /= mx;
    ll rem = k % mx;

    for (i = 0; i < r; i++) {
        mp[p[i]]++;
    }



    ll tot = 0, res;

    vector<bool> taken(n, false);

    for (i = n - 1; i >= 0; i--) {
        if (mp[v[i]] > 0) {
            taken[i] = true;
            mp[v[i]]--; r--;
            tot += (v[i] + (r * mx)) * 1LL * mx;
        }
    }

    r = k + mx - 1; r /= mx;

    if (rem == 0) {
        cout << tot << endl; return;
    }

    res = tot;

    ll curr = 0;
    for (i = 0; i < n; i++) {
        if (taken[i]) {

            // cout << i << endl;
            curr++;
            ll rm = r - curr;
            // cout << rm << " - " << curr << endl;

            ll price = v[i] + (curr - 1) * 1LL * mx;
            // cout << "Price: " << price << endl;

            ll val = tot; val -= price * mx; val += (price * rem);
            val -= (rm * 1LL * mx * (mx - rem));

            // cout << val << " " << i << endl;
            res = min(res, val);
        }
    }

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}