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
    ll  n, i, j, k, r;
    cin >> n >> k >> r;

    if (n == k) {
        cout << 0 << endl; return;
    }

    ll diff = abs(n - k);

    // for (i = 63; i >= 0; i--) {
    //     if((1))
    // }

    bitset<64> a = max(n, k), b = min(n, k);
    ll rr = r;

    ll ans = 0;
    bool f = 0;


    for (i = 63; i >= 0; i--) {
        if ((a[i] ^ b[i]) && f == 0) {
            f = 1; continue;
        }

        if (f && (a[i] ^ b[i]) && !b[i]) {
            ll p = (1LL << i);
            if (p <= r) {
                r -= p;
                ans += p;
            }
        }
    }

    ll ans1 = 0;
    bool ff = 0;

    for (i = 63; i >= 0; i--) {
        if ((a[i] ^ b[i]) && ff == 0) {
            ll p = (1LL << i);
            if (p <= rr) {
                rr -= p; ans1 += p;
                ff = 1; continue;
            }
        }

        if (ff && (a[i] ^ b[i]) && !a[i]) {
            ll p = (1LL << i);
            if (p <= rr) {
                rr -= p;
                ans1 += p;
            }
        }
    }
    ll res1 = abs((n ^ ans1) - (k ^ ans1));
    ll res2 = abs((n ^ ans) - (k ^ ans));

    cout << min({ abs(n - k), res1, res2 }) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
