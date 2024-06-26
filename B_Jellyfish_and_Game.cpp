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
    ll  n, i, j, k, m;
    cin >> n >> m >> k;
    vector<ll>v(n); vin(v);
    vector<ll>vv(m); vin(vv);
    sort(all(v)); sort(all(vv));
    ll sma = 0, smb = 0;
    for (auto x : v) sma += x;
    for (auto x : vv) smb += x;
    if (k == 1) {
        ll ans = max(sma, sma - v[0] + vv[m - 1]);
        cout << ans << endl; return;
    }
    if (k % 2) {
        if (v[0] >= vv[m - 1]) {
            cout << sma << endl; return;
        }
        else {
            cout << sma + vv[m - 1] - v[0] << endl; return;
        }
    }
    else {
        if (v[0] >= vv[m - 1]) {
            cout << sma - v[n - 1] + vv[0] << endl; return;
        }
        else {
            sma += vv[m - 1] - v[0]; sma -= max(vv[m - 1], v[n - 1]); sma += min(v[0], vv[0]);
            cout << sma << endl; return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
