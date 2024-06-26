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

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    string s, t, res; cin >> s >> t;

    res.push_back(s[0]);
    char last = t.back();

    s.erase(s.begin(), s.begin() + 1);
    t.pop_back();

    bool f = 0;

    for (i = 0; i < n - 1; i++) {
        if (f) {
            res += t[i]; continue;
        }

        if (t[i] >= s[i]) {
            res += s[i];
        }
        else {
            res += t[i]; f = 1;
        }
    }

    res.push_back(last);
    cout << res << endl;

    ll ans = 0, li = -1;

    // cout << s << endl;
    // cout << t << endl;

    for (i = 0; i < n; i++) {
        if (t[i] > s[i]) {
            li = i;
        }
        if (t[i] < s[i]) {
            break;
        }
    }

    ans = (i - li - 1);
    if (i != n) ans++;

    cout << ans<< endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
