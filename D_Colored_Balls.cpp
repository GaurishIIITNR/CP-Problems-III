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

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

#ifndef ONLINE_JUDGE
#include "debug.h"
using namespace debug;
#else 
#define deb(x)
#endif

ll f(vector<ll>& v, ll i, ll sm, ll fl) {
    if (i == v.size()) {
        if (fl) return -1;
        return 0;
    }
    ll ans = f(v, i + 1, sm, fl);
    if (sm >= v[i]) ans += v[i] + f(v, i + 1, min(sm + v[i], (ll)1002), (fl + v[i]) % 2);
}


void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<ll> v(n);
    vin(v);


    cout << f(v, 0, 0, 0) << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
