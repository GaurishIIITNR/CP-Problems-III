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

    vector<ll>v(n); vin(v);

    vector<ll> vv = v;

    for (i = 1; i < n; i++) {
        v[i] += v[i - 1];
    }

    // vout(v);

    cin >> k;
    while (k--) {

        ll l, x; cin >> l >> x; --l;

        ll curr = 0;
        if (l - 1 >= 0) curr = v[l - 1];

        if (v[l] - curr >= x) {
            cout << l + 1 << " "; continue;
        }

        ll idx = upper_bound(all(v), (curr + x)) - v.begin();

        if (idx == n) {
            cout << n << " "; continue;
        }

        // cout << idx + 1 << endl;

        ll diff = v[idx] - curr;
        
        ll per = (x * (x + 1)); per /= 2;
        ll k = diff - x - 1; k = (k * (k + 1)) / 2;

        // cout << diff << endl;

        per -= k;
        diff -= vv[idx];

        // cout << diff << endl;

        ll perl = ((2 * x) - (diff - 1)); perl *= diff;
        perl /= 2;

        // cout << perl << " - " << per << endl;
        if (perl >= per) {
            cout << idx << " ";
        }
        else {
            cout << idx + 1 << " ";
        }
    }

    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
