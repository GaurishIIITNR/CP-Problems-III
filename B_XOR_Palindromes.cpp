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
    cin >> n;  string s; cin >> s;
    ll l = 0, h = n - 1;
    ll cnt = 0;
    while (l < h) {
        if (s[l] != s[h]) cnt++;
        l++, h--;
    }
    string res = "";
    for (i = 0; i <= n;i++) {
        if (cnt > i) {
            res += "0";
        }
        else {
            ll n1 = n;
            n1 -= (2 * cnt); ll i1 = i - cnt;
            // cout << n1 << " " << i1 << endl;
            if (n % 2 && n1 >= i1) {
                res += "1";
            }
            else if (n % 2) res += "0";
            else if (n1 >= i1 && i1 % 2 == 0) res += "1";
            else res += "0";
        }
    } //res += res[0];
    cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
