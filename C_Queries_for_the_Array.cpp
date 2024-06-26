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
    string s; cin >> s;
    n = s.size();
    vector<bool>sor, unsr;
    for (i = 0;i < n; i++) {
        if (sor.size() == 0) {
            if (s[i] == '0') {
                cout << "NO\n"; return;
            }
            if (s[i] == '+')  sor.pb(1), unsr.pb(0);

        }
        else {

            if (s[i] == '+') {
                if (sor.back())  sor.pb(1), unsr.pb(1);
                else  sor.pb(0), unsr.pb(1);
            }

            if (s[i] == '-') {
                bool a = sor.back(), b = unsr.back();
                sor.pop_back(), unsr.pop_back();
                if (sor.size() > 0 && a == 1 && b == 0) {
                    ll sz = sor.size();
                    sor[sz - 1] = 1, unsr[sz - 1] = 0;
                }
            }

            if (s[i] == '1') {
                if (sor.back() == 0) { cout << "NO\n"; return; }
                sor.pop_back(), unsr.pop_back();
                sor.pb(1), unsr.pb(0);
            }

            if (s[i] == '0') {
                if (unsr.back() == 0) {
                    cout << "NO\n"; return;
                }
                sor.pop_back(), unsr.pop_back();
                sor.pb(0), unsr.pb(1);
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        HHM();
    }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
