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

vector<ll>pr;
void primes(ll n) {
    vector<bool>v(n + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            pr.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }
    return;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    ll ans = INT_MAX;

    if (((n + 1) & (n)) == 0) {
        ans = (ll)log2(n);
    }


    for (auto x : pr) {
        if (x > n) break;
        ll rem = n - x;

        if (rem == 0) {
            ans = min(ans, (ll)1);
        }

        rem++;
        if ((rem & (rem - 1)) == 0) {
            ans = min(ans, (ll)log2(rem) + 1);
        }
    }

    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    primes(1e6 + 2);
    cin >> t;
    while (t--) { HHM(); }
}
