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

ll dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

bool f(ll i, ll j, ll k, set<vector<ll>> s, ll n, ll m) {
    if (k == 0) {
        // cout << i << " " << j << endl;
        if (i == n - 1 && j == m - 1) {
            return true;
        }
        return false;
    }

    bool ans = false;

    for (int ii = 0; ii < 4; ii++) {
        ll x = i + dir[ii][0];
        ll y = j + dir[ii][1];

        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (s.find({ i, j , x, y }) == s.end() && s.find({ x, y , i, j }) == s.end()) {
                // cout << i << " " << j << " " << x << " " << y << endl;
                s.insert({ i, j , x, y });
                ans |= f(x, y, k - 1, s, n, m);
                if (ans) return ans;
            }
        }
    }

    return ans;
}

void HHM() {
    ll  n, i, j, k, m;
    cin >> n >> m >> k;

    ll cnt = n * (m - 1); cnt += (n - 1) * m;

    if (cnt < k) {
        cout << "NO" << endl; return;
    }

    set<vector<ll>> vis;
    bool ans = f(0, 0, k, vis, n, m);

    if (ans) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
