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

const ll N = 1e6 + 1;
const ll MOD = 1000000007; // 998244353 
ll F[N], iF[N]; // Don't forget to change the value of N. factorial,Inverse Factorial Array
// if you want to use without any mod than mod will be INF 

ll fast(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    F[0] = 1;

    for (ll i = 1; i < N; ++i)
        F[i] = (F[i - 1] * i) % MOD;

    iF[0] = fast(1, MOD - 2);

    for(ll i = 1; i < N; i++) {
        iF[i] = iF[i - 1] * fast(i, MOD - 2) % MOD;
    }
}

ll NCR(ll n, ll r) {
    if (r > n || r < 0)
        return 0;
    return iF[r] * F[n] % MOD * iF[n - r] % MOD;
}

ll gpsm(ll r, ll n) {
    ll x = fast(r, n); x--; x += MOD; x %= MOD;
    ll y = fast(r - 1, MOD - 2); y %= MOD;
    return (x * y) % MOD;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<pair<ll, ll>> vp(n);

    ll tot = 1, sm = 1;

    ll tt = 0;

    for (i = 0; i < n; i++) {

        cin >> vp[i].F >> vp[i].S; tot *= (vp[i].S + 1); tot %= mod;
        sm *= gpsm(vp[i].F, vp[i].S + 1); sm %= mod;

        tt += vp[i].S;
    }

    cout << tot << " " << sm << " ";

    vector<ll> pref(n, 1);
    vector<ll> suff(n, 1);

    for (i = 0; i < n; i++) {
        pref[i] *= vp[i].S + 1; pref[i] %= (mod - 1);
        if (i) pref[i] *= pref[i - 1]; pref[i] %= (mod - 1);
    }

    for (i = n - 1; i >= 0; i--) {
        suff[i] *= vp[i].S + 1; suff[i] %= (mod - 1);
        if (i < n - 1) suff[i] *= suff[i + 1]; suff[i] %= (mod - 1);
    }

    ll res = 1;

    for (i = 0; i < n; i++) {
        ll nn = vp[i].S; nn *= (vp[i].S) + 1; nn /= 2; nn %= (mod - 1);
        if (i - 1 >= 0) nn *= pref[i - 1]; nn %= (mod - 1);
        if (i + 1 < n) nn *= suff[i + 1]; nn %= (mod - 1);
        res *= fast(vp[i].F, nn); res %= mod;
    }

    cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    init();

    while (t--) { HHM(); }
}
