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
#define ll int
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

vector<ll>pr;

void primes(ll n) {
    vector<bool>v(n + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            pr.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }
    return;
}

void factors(ll n, umap<ll, ll>& mp, ll p) {
    mp.clear();
    for (auto x : pr) {
        if (x * x > n)break;
        while (n % x == 0) {
            mp[x] += p;
            n /= x;
        }
    }
    if (n > 1)mp[n] += p;
    return;
}

// bool check = 0;
// ll binpow(ll a, ll b, ll val) {
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1) {
//             res = (res * a);
//             if (res % val == 0 && __gcd(res, (val * val)) > 1) check = 1;
//             res %= val;
//         }
//         a = (a * a) % val;
//         b >>= 1;
//     }
//     return res;
// }

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    umap<ll, ll>nn;
    vector<ll>div;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.pb(i);
            if (i * i != n)div.pb(n / i);
        }
    }

    while (k--) {
        ll p; cin >> p; p--;
        ll ans = 0;

        for (auto& gcd : div) {
            umap<ll, ll>mp;
            factors((n / gcd), nn, 1LL);
            factors(gcd, mp, p);

            bool f = 0;
            for (auto x : nn) {
                if (x.S != mp[x.F]) {
                    f = 1; break;
                }
            }

            if (!f) {
                ans++;  ans %= mod;
            }
        }


}

cout << ans << endl;
}
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    primes(sqrtl(1e9) + 4);
    while (t--) { HHM(); }
}
