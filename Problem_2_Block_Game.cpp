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
    vector<ll>ans(26, 0);

    while (n--) {
        string a, b; cin >> a >> b;
        vector<ll>c(26, 0), d(26, 0);
        for (auto x : a)  c[x - 'a']++;
        for (auto x : b) d[x - 'a']++;
        for (i = 0; i < 26; i++) {
            ans[i] += max(c[i], d[i]);
        }
    }

    for (i = 0; i < 26; i++) cout << ans[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    freopen("blocks.in", "r", stdin);  freopen("blocks.out", "w", stdout);
    while (t--) { HHM(); }
}
