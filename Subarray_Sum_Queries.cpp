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
long long int mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

void build(ll i, vector<vector<ll>>& tr, ll s, ll e, vector<ll>& v) {
    if (s == e) {
        tr[i][0] = v[s]; tr[i][1] = v[s];
        tr[i][2] = v[s]; tr[i][3] = v[s];
        return;
    }

    ll m = (s + e) / 2;

    build(2 * i, tr, s, m, v);
    build(2 * i + 1, tr, m + 1, e, v);

    tr[i][1] = max(tr[2 * i][1], tr[2 * i][3] + tr[2 * i + 1][1]);
    tr[i][2] = max(tr[2 * i][2] + tr[2 * i + 1][3], tr[2 * i + 1][2]);
    tr[i][3] = tr[2 * i][3] + tr[2 * i + 1][3];
    tr[i][0] = max(tr[2 * i][2] + tr[2 * i + 1][1], max(tr[2 * i][0], tr[2 * i + 1][0]));

    return;
}

void upd(ll i, vector<vector<ll>>& tr, ll s, ll e, ll l, ll r, ll u) {
    if (s == e && s >= l && s <= r) {
        tr[i][0] = u; tr[i][1] = u;
        tr[i][2] = u; tr[i][3] = u;
        return;
    }

    if (s > r || e < l) return;
    ll m = (s + e) / 2;

    upd(2 * i, tr, s, m, l, r, u);
    upd(2 * i + 1, tr, m + 1, e, l, r, u);

    tr[i][1] = max(tr[2 * i][1], tr[2 * i][3] + tr[2 * i + 1][1]);
    tr[i][2] = max(tr[2 * i][2] + tr[2 * i + 1][3], tr[2 * i + 1][2]);
    tr[i][3] = tr[2 * i][3] + tr[2 * i + 1][3];
    tr[i][0] = max(tr[2 * i][2] + tr[2 * i + 1][1], max(tr[2 * i][0], tr[2 * i + 1][0]));

    return;
}

vector<ll> query(ll i, vector<vector<ll>>& tr, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) return { INT_MIN,INT_MIN,INT_MIN,INT_MIN };
    if (l <= s && e <= r) return tr[i];
    ll m = (s + e) / 2;
    vector<ll>a = query(2 * i, tr, s, m, l, r);
    vector<ll>b = query(2 * i + 1, tr, m + 1, e, l, r);

    vector<ll>ans(4, 0);
    
    ans[1] = max(a[1], a[3] + b[1]);
    ans[2] = max(a[2] + b[3], b[2]);
    ans[3] = a[3] + b[3];
    ans[0] = max(a[2] + b[1], max(a[0], b[0]));

    return ans;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    vector<ll>v(n); vin(v);
    
    vector<vector<ll>>tr(4 * n + 1, vector<ll>(4, 0));
    build(1, tr, 0, n - 1, v);

    while (k--) {
        ll x, y;cin >> x >> y; --x;
        upd(1, tr, 0, n - 1, x, x, y);
        vector<ll>ans = query(1, tr, 0, n - 1, 0, n - 1);
        cout << (ans[0] > 0 ? ans[0] : 0) << "\n";
    }

    return;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case #" <<i<< ": ";
        HHM();
    }
}

