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
    ll  n, i, j, k, m;
    cin >> n >> m >> k;
    vector<vector<ll>>v(n + 1, vector<ll>(m + 1, 0));
    for (i = n; i >= 0; i--) {
        for (j = m; j >= 0; j--) {
            v[i][j] = 0;
            if (i == n && j == m) v[i][j] = k;
            else {
                if (i + 1 <= n) {
                    if (v[i + 1][j] >= k)
                        v[i][j] += k;
                }
                if (j + 1 <= m) {
                    if (v[i][j + 1] >= k)
                        v[i][j] += k;
                }
            }
        }
    }

    ll sm = 0;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0) sm += v[i][j];
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    cout << sm << "\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
