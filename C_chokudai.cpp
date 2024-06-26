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

ll dp[100005][10];

ll f(string & s, string & tar, int i, int j) {
    if (j == tar.size()) {
        return 1;
    }
    if (i == s.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    ll ans = 0;
    if (s[i] == tar[j]) {
        ans += f(s, tar, i + 1, j + 1); ans %= mod;
    }
    ans += f(s, tar, i + 1, j); ans %= mod;

    return dp[i][j] = ans;
}

void HHM() {
    ll  n, i, j, k;
    // cin >> n;  

    string s; cin >> s;
    string tar = "chokudai";
    memset(dp, -1, sizeof(dp));

    cout << f(s, tar, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
