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
    cin >> n >> k;
    vector< vector<char>>v(n, vector<char>(k, '.'));
    for (i = 0;i < n;i++) {
        for (j = 0;j < k;j++) {
            cin >> v[i][j];
        }
    }
    vector<ll>rw(n, 0), rb(n, 0);
    vector<vector<char>>ans(n, vector<char>(k, '.'));

    for (i = 0;i < n;i++) {
        for (j = 0;j < k; j++) {
            if (v[i][j] == 'U') {
                if (rw[i] > rb[i]) {
                    ans[i][j] = 'B'; rb[i]++;
                    ans[i + 1][j] = 'W', rw[i + 1]++;
                }
                else {
                    ans[i][j] = 'W'; rw[i]++;
                    ans[i + 1][j] = 'B', rb[i + 1]++;
                }
            }
        }
        if (rw[i] != rb[i]) {
            cout << -1 << endl; return;
        }
    }
    vector<ll>cw(k, 0), cb(k, 0);
    for (j = 0;j < k;j++) {
        for (i = 0;i < n; i++) {
            if (v[i][j] == 'L') {
                if (cw[j] > cb[j]) {
                    ans[i][j] = 'B'; cb[j]++;
                    ans[i][j + 1] = 'W', cw[j + 1]++;
                }
                else {
                    ans[i][j] = 'W'; cw[j]++;
                    ans[i][j + 1] = 'B', cb[j + 1]++;
                }
            }
        }
        if (cw[j] != cb[j]) {
            cout << -1 << endl; return;
        }
    }
    for (i = 0;i < n;i++) {
        for (j = 0; j < k;j++) {
            cout << ans[i][j];
        } cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
