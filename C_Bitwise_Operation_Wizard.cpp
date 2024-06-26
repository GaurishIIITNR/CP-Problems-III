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

char qr(ll a, ll b, ll c, ll d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char e; cin >> e;
    return e;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    if (n == 2) {
        cout << "! " << 0 << " " << 1 << endl; return;
    }

    ll bada = 0;

    for (i = 1; i < n; i++) {
        char c = qr(bada, bada, i, i);
        if (c == '<') {
            bada = i;
        }
    }

    ll ans = -1;
    for (i = 0; i < n; i++) {
        if (i == bada) continue;

        if (ans == -1) {
            ans = i; continue;
        }

        char c = qr(bada, ans, bada, i);
        if (c == '>') {  // and(&) lene me minimum possible (zero hoga)
            ans = i; continue;
        }
        else if (c == '=') {  // koi aur minimum ke equal ho gaya
            if (qr(ans, bada, bada, i) == '<') { // ussme jiska or(|) bada hoga vo ans hoga
                ans = i;
            }
        }
    }

    cout << "! " << ans << " " << bada << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
