// Warning: Coding is an addiction.

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

ll st(string& s, char c, int ocr) {
    ll prev = -1;
    vector<ll> v;
    // cout << c << " - " << ocr << endl;

    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            v.pb(i);
        }
    }

    // vout(v);

    ll cnt = 1, mx = 1;
    ll sm = 0, l = 0;

    for (ll i = 0; i < v.size(); i++) {
        if (v[i] - v[l] < ocr) {
            mx = max(mx, i - l + 1); continue;
        }

        while (l <= i && v[i] - v[l] >= ocr) {
            l++; cnt--;
        }

        mx = max(mx, i - l + 1);
    }

    return ocr - mx;
}

void HHM() {
    ll  n, i, j, k;
    string s; cin >> s;

    umap<char, ll> mp;

    for (auto x : s)mp[x]++;
    for (auto x : mp) {
        if (x.S == 1) {
            cout << 0 << endl; return;
        }
    }

    ll res = INT_MAX;

    for (auto x : mp) {
        res = min(res, st(s, x.F, x.S));
    }

    cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
