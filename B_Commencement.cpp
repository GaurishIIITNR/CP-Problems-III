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
#define vin(v) for(auto &z: v)cin >> z

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

#ifndef ONLINE_JUDGE
#include "debug.h"
using namespace debug;
#else 
#define deb(x)


#endif
void HHM() {
    ll  n, i, j, k;
    // cin >> n;  

    string s; cin >> s;
    n = s.size();
    vector<ll> v(26, 0);

    for (i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }


    for (i = 1; i <= n; i++) {
        ll cnt = 0;

        for (auto x : v) {
            if (x == i) cnt++;
        }

        if (cnt > 0 && cnt != 2) {
            cout << "No"; return;
        }
    }

    cout << "Yes";


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
