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

vector<vector<bool>> dp;
vector<vector<bool>> vis;

bool f(vector<ll>& v, ll i, ll tar, ll& n) {
    if (i == v.size()) {
        return tar == 0;
    }
    if (vis[i][tar]) return dp[i][tar];

    ll a = tar - v[i]; a %= n; a += n; a %= n;

    vis[i][tar] = 1;
    return dp[i][tar] = (f(v, i + 1, a, n) | f(v, i + 1, (tar + v[i]) % n, n));
}

void HHM() {
    ll  n, i, j, k, cur;
    cin >> n >> k >> cur; --cur;

    dp.assign(k + 1, vector<bool>(n + 1, 0));
    vis.assign(k + 1, vector<bool>(n + 1, 0));

    vector<ll> v;
    ll ans = 0;

    for (i = 0; i < k; i++) {
        ll d; cin >> d;
        char c; cin >> c;

        if (c == '0') {
            ans += d;
        }
        else if (c == '1') ans -= d;
        else {
            v.push_back(d);
        }
    }

    cur += ans; cur %= n; cur += n; cur %= n;

    vector<ll>res;

    for (i = 0; i < n; i++) {
        if (f(v, 0, i, n)) {
            res.push_back(i);
        }
    }

    set<ll>fi;
    for (auto x : res) {
        ll op = (cur + x); op %= n;
        fi.insert(op + 1);
    }

    cout << fi.size() << endl;
    for (auto x : fi) {
        cout << x << " ";
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
