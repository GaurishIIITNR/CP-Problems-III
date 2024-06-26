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

    vector<ll> v(n);

    ll sm = 0;

    for (auto& x : v) {
        cin >> x; sm += x; x %= 3;
    }

    sm %= 3;

    if (sm == 0) {
        cout << "0\n"; return;
    }

    sort(all(v));
    reverse(all(v));
    ll op = 0, ans = (3 - sm) % 3;

    for (i = 0; i < n; i++) {
        if (v[i] == 0) continue;
        if (sm == 0) break;
        if (v[i] <= sm) {
            sm -= v[i]; op++;
        }
    }

    ll rem = (3 - sm) % 3;
    op += rem;

    cout << min(ans, op) << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
