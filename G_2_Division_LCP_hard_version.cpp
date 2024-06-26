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

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

#ifndef ONLINE_JUDGE
#include "debug.h"
using namespace debug;
#else 
#define deb(x)
#endif

bool ok(string& s, ll m, ll k) {
    string t = s.substr(0, m);
    vector<ll> lps(m, 0);

    for (ll i = 1; i < m; i++) {
        ll j = lps[i - 1];
        while (j > 0 && t[i] != t[j]) {
            j = lps[j - 1];
        }

        if (t[i] == t[j]) {
            lps[i] = ++j;
        }
    }

    ll j = 0, cnt = 0;
    for (ll i = 0; i < s.size(); i++) {
        while (j > 0 && t[j] != s[i]) {
            j = lps[j - 1];
        }

        if (t[j] == s[i]) {
            j++;
        }

        if (j == m)cnt++;
        j %= m;
    }

    return cnt >= k;
}

void HHM() {
    ll  n, i, j, k, p;

    cin >> n >> k >> p;
    string s; cin >> s;

    vector<ll> ans = { n / k };
    bool flag = false;

    for (i = k; i <= p; i++) {
        if (flag) {
            ans.pb(0); continue;
        }

        ll l = 0, h = min(n / i, ans.back());
        while (l < h) {
            ll m = l + (h - l + 1) / 2;
            if (ok(s, m, i)) l = m;
            else h = m - 1;
        }

        ans.pb(l);
        if (ans.back() == 0) {
            flag = 1;
        }
    }

    for (i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
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
