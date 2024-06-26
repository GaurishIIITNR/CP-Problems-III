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
#define vin(v) for(auto &z: v)

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> multisat;

vector<vector<ll>> v;

ll row(ll i) {
    ll sm = 0;

    for (auto x : v[i]) {
        sm += x;
    }

    return sm;
}

ll col(ll j) {
    ll sm = 0;

    for (ll i = 0; i < v.size(); i++) {
        sm += v[i][j];
    }

    return sm;
}

ll HHM() {
    ll n, i, j, k;
    cin >> n;

    ll sm = 0, op = 0, cr = 0, cc = 0;
    v.assign(n, vector<ll>(n, 0));

    bool f = 0;
    ll tot = (n * (n + 1)) / 2;

    vector<vector<ll>> ans;

    while (op < (2 * n)) {
        ll rsm = row(cr), csm = col(cc);
        if (rsm >= tot && csm >= tot) {
            break;
        }

        if (!f) {
            if (rsm < tot) {
                ans.pb({ 1, cr + 1 });
                sm -= rsm; sm += tot;
                for (i = 0; i < n; i++) {
                    v[cr][i] = i + 1;
                    ans[op].pb(i + 1);
                }
                op++; cr++;
                if (cr == n) {
                    f = 1; cr = 0;
                }
            }
            else {
                f = 1; cr = 0;
            }
        }
        else {
            if (csm < tot) {
                ans.pb({ 2, cc + 1 });
                sm -= csm; sm += tot;
                for (i = 0; i < n; i++) {
                    v[i][cc] = i + 1;
                    ans[op].pb(i + 1);
                }

                op++; cc++;  
                if (cc == n) {
                    f = 0; cc = 0;
                }
            }
            else {
                f = 0; cc = 0;
            }
        }
    }

    cout << sm << " " << op << endl;
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        HHM();
    }
    return 0;
}
