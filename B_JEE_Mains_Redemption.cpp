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


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a; res %= mod;
        }
        a = a * a; a %= mod;
        b >>= 1;
    }
    return res;
}

map<ll, ll> dp;

ll f(ll n, ll k) {
    if (n == 1) return k;
    if (dp.find(n) != dp.end()) return dp[n] % mod;

    if (n % 2 == 1) {
        ll l = n / 2, r = (n + 1) / 2;

        ll a = f(l, k) * f(r, k); a %= mod;
        a -= k;a %= mod; a += mod; a %= mod;

        return dp[n] = a % mod;
    }

    else {

        ll p = f(n / 2, k);
        ll a = binpow(p, 2); a %= mod;
        a -= 2; a %= mod; a += mod; a %= mod;

        return dp[n] = a % mod;
    }

}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    dp.clear();
    cout << f(n, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
