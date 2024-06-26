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

void HHM() {
    ll  n, i, j, k;
    cin >> n;
    umap<ll, ll>m, m1;
    vector<ll>v(n); vin(v);

    for (j = 0;j < n;j++) {
        ll x; cin >> x; m[v[j]] += x;
    }

    cin >> k; v.clear(); v.resize(k); vin(v);

    for (j = 0;j < k;j++) {
        ll x; cin >> x; m1[v[j]] += x;
    }

    for (auto [a, b] : m1) {
        m[a] -= b;
    }

    ll res = 1;
    for (auto x : m) {
        if (x.S < 0) {
            cout << 0 << endl; return;
        }
        if (x.S > 0) res = (res * 2) % mod;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
