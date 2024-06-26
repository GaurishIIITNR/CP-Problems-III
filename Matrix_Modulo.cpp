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

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    map<ll, ll> mp;

    vector<vector<ll>>v(n, vector<ll>(n, 0));

    ll val = (n * n) - n; val /= 2; val = (n * n) - val;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j] > 0) mp[v[i][j] % val]--;
        }
    }



    for (i = 1; i <= n * n; i++) {
        mp[i % val]++;
    }

    ll res = 1;
    ll c = 0, d = 0;

    vector<vector<bool>>ch(n, vector<bool>(n, 0));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (ch[i][j]) continue;

            if (i == j) {
                if (v[i][j] == 0) c++;
                else if (v[i][j] % val != 0 && (v[i][j] % val) <= (val - n)) {
                    cout << 0 << endl; return;
                }
                continue;
            }

            if (v[i][j] == 0 && v[j][i] == 0) {
                d++; ch[i][j] = 1; ch[j][i] = 1;
            }

            else if (v[i][j] != 0 && v[j][i] != 0) {
                if (v[i][j] % val != v[j][i] % val) {
                    cout << 0 << endl; return;
                }
                ch[i][j] = 1; ch[j][i] = 1;
            }

            else if (v[i][j] != 0) {
                if (mp[v[i][j] % val] == 0) {
                    cout << 0 << endl; return;
                }
                ch[i][j] = 1; ch[j][i] = 1;
                res *= mp[v[i][j] % val]; res %= mod; mp[v[i][j] % val]--;
            }
            else {
                if (mp[v[j][i] % val] == 0) {
                    cout << 0 << endl; return;
                }
                ch[i][j] = 1; ch[j][i] = 1;
                res *= mp[v[j][i] % val]; res %= mod; mp[v[j][i] % val]--;
            }
        }
    }

    for (i = 1; i <= c; i++) {
        res *= i; res %= mod;
    }

    for (i = 2 * d; i > 0; i -= 2) {
        res *= i; res %= mod;
    }

    cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
