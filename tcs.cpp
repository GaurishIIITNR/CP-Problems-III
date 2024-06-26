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

bool pr(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void HHM() {
    ll  n, i, j, k;
    vector<ll>v;

    while (cin >> n) {
        v.push_back(n);
    }

    if (v.size() == 1) {
        if (pr(v[0])) {
            cout << v[0] << endl; return;
        }
        cout << "None" << endl; return;
    }

    sort(v.begin(), v.end());

    ll lcm = v[1];
    for (i = 1; i < (ll)v.size(); i++) {
        ll g = __gcd(lcm, v[i]);
        if ((lcm * (v[i] / g)) + v[0] >= 1e10) {
            cout << "None"; return;
        }
        lcm = lcm * (v[i] / g);
    }

    lcm += v[0];
    
    if (pr(lcm)) {
        cout << lcm << endl;  return;
    }
    cout << "None" << endl; return;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    while (t--) { HHM(); }
}
