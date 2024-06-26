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
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

void ch(vector<ll>& a, ll i) {
    ll aa = a[i] + a[i + 1] + a[i + 2];
    ll bb = -a[i + 2];
    ll cc = -a[i + 1];
    ll dd = a[i + 3] + a[i + 2] + a[i + 1];
    a[i] = aa, a[i + 1] = bb, a[i + 2] = cc, a[i + 3] = dd;
    return;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<ll> a(n), b(n), a1; vin(a); vin(b); a1 = a;
    bool x = 1, y = 1;

    for (i = n - 4; i >= 0; i--) {
        if (a[i + 3] == b[i + 3]) continue;

        ch(a, i);
        if (a[i + 3] == b[i + 3]) {
            continue;
        }

        ch(a, i);
        if (a[i + 3] == b[i + 3]) {
            continue;
        }

        x = 0; break;
    }

    if (x && a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        cout << "YES\n"; return;
    }

    a = a1; x = 1;

    for (i = 0; i < n - 3; i++) {
        if (a[i] == b[i]) continue;

        ch(a, i);
        if (a[i] == b[i]) {
            continue;
        }

        ch(a, i);
        if (a[i] == b[i]) {
            continue;
        }

        x = 0; break;
    }

    if (x && a[n - 3] == b[n - 3] && a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]) {
        cout << "YES\n"; return;
    }

    cout << "NO\n"; return;



}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
