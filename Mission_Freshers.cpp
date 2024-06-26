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

void factors(ll n, map<ll, ll>& m) {
    for (auto x : pr) {
        if (x * x > n)break;
        while (n % x == 0) {
            m[x]++;
            n /= x;
        }
    }
    if (n > 1) m[n]++;
    return;
}
void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;

    map<ll, ll> lcm;
    for (i = 0; i < n; i++) {
        ll d; cin >> d;
        factors(d, lcm);
    }
    
    for (auto x : pr) {
        if (x * x > k)break;
        while (k % x == 0) {
            if (lcm[x] <= 0) {
                cout << "No";
                return;
            }
            lcm[x]--;
            k /= x;
        }
    }
    if (k > 1) {
        if (lcm[k] <= 0) {
            cout << "No";
            return;
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
    primes(1e3 + 5);
    while (t--) { HHM(); }
}
