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

vector<pair<ll, ll>> pz = { {1,1}, {-1,-1}, {-1,1}, {1,-1} };

ll f(vector<ll>& p, ll l) {
    if (p[0] + p[1] + p[2] + p[3] == 0) {
        return 1;
    }

    ll ans = 0;
    for (ll i = 0; i < 4; i++) {
        if (p[i] == 0) continue;
        if (l == 0) {
            p[i]--;
            ans += f(p, pz[i].second); ans %= mod;
            p[i]++;
        }
        else if (l + pz[i].first == 0) {
            p[i]--;
            ans += f(p, pz[i].second); ans %= mod;
            p[i]++;
        }
    }

    ans %= mod;
    return ans;
}

void HHM() {
    ll  n, i, j, k;

    vector<ll> v(4); vin(v);
    // vout(v);

    cout << f(v, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
