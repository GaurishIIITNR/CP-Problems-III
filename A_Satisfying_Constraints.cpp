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
    cin >> n;
    ll mx = 0, mn = INT_MAX;

    vector<ll>v;
    for (i = 0; i < n; i++) {
        ll x, r; cin >> x >> r;
        if (x == 1) {
            mx = max(mx, r);
        }
        else if (x == 2) {
            mn = min(mn, r);
        }
        else v.pb(r);
    }

    if (mx > mn) {
        cout << 0 << endl; return;
    }
    ll ans = mn - mx + 1;

    for (auto x : v) {
        if (x >= mx && x <= mn) ans--;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0); 
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while(t--){ HHM(); }
}
