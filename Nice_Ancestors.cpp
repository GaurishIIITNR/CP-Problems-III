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

const ll N = 200000;
vector<ll> v[N + 1]; ll vv[N + 1];

void ff(ll d) {
    queue<pair<ll, ll>> q; q.push({ d, 0 });
    while (!q.empty()) {
        ll first = q.front().first, second = q.front().second; q.pop();
        for (auto xx : v[first]) {
            q.push({ xx, second + 1 }); vv[xx] = (second == 0) ? -1 : first;
        }
    }
}

int main() {
    ll t; cin >> t;

    while (t--) {
        ll  n, k, i, j;  cin >> n >> k;
        for (j = 1; j <= n; ++j) {
            v[j].clear(); vv[j] = -1;
        }
        for (j = 2; j <= n; ++j) {
            ll l; cin >> l;
            v[l].push_back(j);
        } ff(1);
        for (j = 1; j <= n; ++j) {
            ll m = j; for (ll oo = 0; oo < k && m != -1; ++oo) {
                m = vv[m];
            }
            cout << m << " ";
        }  cout << endl;
    }
}