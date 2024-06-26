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

void HHM() {
    ll  n, i, k;

    string s; cin >> s;
    n = s.size();


    if (n < 3) {
        cout << "Just a legend"; return;
    }

    vector<ll> lps(n, 0);

    set<ll> st;

    for (i = 1; i < n - 1; i++) {
        ll j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }

        if (s[j] == s[i]) {
            lps[i] = ++j;
            st.insert(lps[i]);
        }
    }

    ll ans = 0;

    ll j = lps[n - 2];
    while (j > 0) {
        if (s[i] == s[j] && st.find(j + 1) != st.end()) {
            cout << s.substr(0, j + 1); return;
        }
        j = lps[j - 1];
    }

    if (s[j] == s[i] && st.find(j + 1) != st.end()) {
        cout << s.substr(0, j + 1); return;
    }

    cout << "Just a legend";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
