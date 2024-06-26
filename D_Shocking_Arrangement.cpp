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

    vector<ll> p, ne;
    ll mn = INT_MAX, mx = INT_MIN;

    for (i = 0; i < n; i++) {
        cin >> k; mx = max(mx, k); mn = min(mn, k);
        if (k >= 0) p.pb(k);
        else ne.pb(k);
    }

    ll diff = mx - mn; sort(all(p)); //reverse(all(p)); 
    sort(all(ne));

    vector<ll> ans;
    ll l = 0, sm = 0;

    for (i = p.size() - 1; i >= 0; i--) {
        if (sm + p[i] < diff) {
            sm += p[i];
            ans.pb(p[i]);
        }
        else {
            bool f = 0;
            while (l < ne.size()) {
                sm += ne[l];
                ans.pb(ne[l]); l++;
                if (sm + p[i] < diff) {
                    sm += p[i];
                    ans.pb(p[i]);
                    f = 1;
                    break;
                }
            }

            if (!f) {
                cout << "No\n";
                return;
            }
        }
    }

    while(l < ne.size()) {
        sm += ne[l];
        ans.pb(ne[l]);
        l++;
    }

    cout << "Yes\n";
    for(auto x: ans) cout << x << " "; cout << "\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
