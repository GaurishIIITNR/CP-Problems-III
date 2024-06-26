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

    vector<ll>v(n); vin(v); sort(all(v));
    map<ll, bool > mp;

    if (n == 1) {
        cout << 1 << endl;  return;
    }

    ll g = 0, sm = 0, ans = LLONG_MAX;

    for (i = 0; i < n; i++) {
        g = __gcd(g, v[n - 1] - v[i]); mp[v[i]] = 1;
        sm += v[n - 1] - v[i];
    }

    for (i = 0; i < n; i++) {
        if (mp[v[i] - g]) continue;
        else {
            ll nans = (v[n - 1] - (v[i] - g)) + sm;
            nans += g - 1; nans /= g;
            ans = min(ans, nans);
        }
    }

    ll nans = sm + (g * n);
    nans += g - 1; nans /= g;
    ans = min(ans, nans);
    
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
