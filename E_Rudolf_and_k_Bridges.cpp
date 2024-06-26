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

ll f(vector<ll>& v, ll d) {
    ll n = v.size(); vector<ll> dp(n, 0);

    deque<ll> dq;
    for (ll i = 0; i < n; i++) {
        while (dq.size() && dq.front() < i - d) dq.pop_front();

        if (dq.size() == 0) {
            dp[i] = v[i] + 1;
            dq.push_back(i);
            continue;
        }
        else {
            dp[i] = v[i] + dp[dq.front()] + 1;
            while (dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
    }

    return dp[n - 1];
}

void HHM() {
    ll  n, i, j, k, m, d;
    cin >> n >> m >> k >> d;

    vector<ll> ans; d++;

    for (i = 0; i < n; i++) {
        vector<ll> v(m); vin(v);
        ll val = f(v, d);
        ans.pb(val);
    }

    for (i = 1; i < n; i++) {
        ans[i] += ans[i - 1];
    }

    ll res = ans[k - 1];

    for (i = k; i < n; i++) {
        res = min(res, ans[i] - ans[i - k]);
    }

    cout << res << endl; return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
