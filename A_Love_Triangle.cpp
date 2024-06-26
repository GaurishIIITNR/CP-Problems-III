// Gaurish Ojha (211020418)

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
    cin >> n; vector<ll>par(n + 1, 0);
    
    for (i = 1; i <= n; i++) {
        cin >> par[i];
    }

    for (i = 1; i <= n; i++) {
        bool love = false;
        ll a = i, b = par[a], c = par[b], d = par[c];
        if (a == d) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--){ HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
