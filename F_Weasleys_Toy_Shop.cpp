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

ll chnge(ll n) {
    bitset<11> b = 0LL;

    while (n > 0) {
        ll rem = n % 10;
        b[rem] = 1;
        n /= 10;
    }

    return (ll)b.to_ullong();
}

void HHM() {
    ll n; cin >> n;
    ll i, j, k;

    vector<ll>v(n); vin(v);
    vector<ll>b(n); vin(b);

    vector<vector<ll>>cnt(2050, vector<ll>(4, 0));

    for (i = 0; i < n; i++) {
        ll y = chnge(v[i]);
        cnt[y][b[i]]++;
    }

    ll ans = 0;
    for (i = 0; i < 2050; i++) {
        for (j = i + 1; j < 2050; j++) {
            if ((i & j) == 0) {
                for (k = 0; k < 4; k++) {
                    for (ll l = 0; l < 4; l++) {
                        if (k != l) {
                            ans += cnt[i][k] * cnt[j][l];
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
