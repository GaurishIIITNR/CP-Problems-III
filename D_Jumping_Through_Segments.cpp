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


bool ok(vector<pair<ll, ll>>& vp, ll k) {
    ll n = vp.size(), mn = 0, mx = 0;
    for (ll i = 0; i < n; i++) {
        mn = mn - k, mx = mx + k;
        if (mn > vp[i].S || mx < vp[i].F) return false;
        mn = max(mn, vp[i].F);
        mx = min(mx, vp[i].S);
    }

    return true;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;
    vector<pair<ll, ll>>vp;
    map<ll, ll>mp;

    for (i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        vp.pb({ x, y });
    }

    ll l = 0, h = 1e9 + 1;

    while (l < h) {
        ll m = l + (h - l) / 2;
        if (ok(vp, m)) h = m;
        else  l = m + 1;
    }

    cout << l << endl; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
