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

bool check(string& s) {
    string p = s;
    reverse(all(p));
    return p == s;
}

void HHM() {
    ll  n, i, j, k;

    string s; cin >> s;

    n = s.size();
    // cout << n << endl;

    if (!check(s)) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << s << endl; return;
    }

    set<char> st;

    for (auto x : s) {
        st.insert(x);
    }

    string rev = s; reverse(all(rev));
    string res = rev + "#"; res += s;

    string rres = s + "#"; rres += rev;


    vector<ll> lps(2 * n + 1, 0);

    for (i = 1; i < res.size() - 1; i++) {
        j = lps[i - 1];
        while (j > 0 && res[i] != res[j]) {
            j = lps[j - 1];
        }

        if (res[i] == res[j]) j++;
        lps[i] = j;
    }

    // vout(lps);

    set<ll> ss, pp;
    j = lps[res.size() - 2];

    while (j > 0) {
        if (res[i] == res[j]) {
            ss.insert(j + 1);
        }
        j = lps[j - 1];
    }

    ss.insert(1);

    lps.clear();
    lps.assign(2 * n + 1, 0);

    for (i = 1; i < rres.size() - 1; i++) {
        j = lps[i - 1];
        while (j > 0 && rres[i] != rres[j]) {
            j = lps[j - 1];
        }

        if (rres[i] == rres[j]) j++;
        lps[i] = j;
    }

    // vout(lps);

    j = lps[rres.size() - 2];

    while (j > 0) {
        if (rres[i] == rres[j]) {
            pp.insert(j + 1);
        }
        j = lps[j - 1];
    }

    pp.insert(1);

    // vout(ss);
    // vout(pp);


    for (i = 0; i < n; i++) {
        if (ss.find(n - i - 1) == ss.end() && pp.find(i + 1) == pp.end()) {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s.substr(0, i + 1) << " " << s.substr(i + 1) << endl;
            return;
        }
    }

    cout << "NO" << endl; return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
