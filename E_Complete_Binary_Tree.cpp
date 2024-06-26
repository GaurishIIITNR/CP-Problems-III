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
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll cal(ll lev, ll levreq, ll src, ll n) {
    if (levreq > lev) return 0;
    if (levreq < lev)return binpow((ll)2, levreq);
    ll st = src, end = src;
    while (levreq > 0) {
        st *= 2; end *= 2; end++; levreq--;
    }
    if (st > n) return 0;
    else return min(n, end) - st + 1;
}

void HHM() {
    ll  n, i, j, k, x;
    cin >> n >> x >> k;

    if (k == 0 && x >= 1 && x <= n) {
        cout << 1 << endl; return;
    }

    ll lev = log2(n);
    ll levx = log2(x);
    ll ans = 0;
    if (levx >= k) ans++;
    else {
        ans += cal(lev, k - levx, 1, n);
    }
    if (x % 2) {
        ans += cal(lev, k, x, n);
        if (x / 2 > 0)
            ans += cal(lev, k - 1, x / 2, n);
    }
    else {
        ans += cal(lev, k, x, n);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
