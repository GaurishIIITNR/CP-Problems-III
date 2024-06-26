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

ll dif(ll l, ll r, vector<ll>& a, vector<ll>& b) {
    ll mid = (l + r) / 2;
    ll ans = r - l;

    for (auto x : a) {
        ll idx = upper_bound(all(b), mid - x) - b.begin();
        for (ll i = idx - 2; i < idx + 2; i++) {
            if (i < 0 || i >= b.size()) continue;
            ll y = b[i];
            if (x + y <= r && x + y >= l) {
                ans = min(ans, max(x + y - l, r - x - y));
            }
        }
    }

    return ans;
}

void HHM() {
    ll  n, i, j, k, m;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m), c(k);
    vin(a); vin(b); vin(c);

    sort(all(a)); sort(all(b)); sort(all(c));

    if (n == 2) {
        cout << dif(a[0], a[1], b, c) << endl; return;
    }

    multiset<ll> diff;

    for (i = 1; i < n; i++) {
        diff.insert(a[i] - a[i - 1]);
    }
    auto it = diff.end(); it--;
    ll fnd = *it; diff.erase(it);
    it = diff.end(); it--;
    ll ans = *it;

    if (fnd == ans) {
        cout << ans << endl; return;
    }

    for (i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == fnd) {
            ans = max(dif(a[i - 1], a[i], b, c), ans);
            cout << ans << endl; return;
        }
    }

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
