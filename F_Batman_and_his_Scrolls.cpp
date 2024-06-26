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

struct node {
    map<char, node*>ch;
    bool end = false;
    node() {
        ch.clear();
    }
};

struct tri {
    node* r;
    tri() {
        r = new node();
    }

    void ins(string& s) {
        node* t = r;
        for (auto& x : s) {
            if (t->ch.find(x) == t->ch.end()) {
                t->ch[x] = new node();
            }
            t = t->ch[x];
            t->end = true;
        }
    }

    ll qr(string& s, ll i) {
        node* t = r;
        ll len = 0;

        for (ll j = i; j < s.size(); j++) {
            char x = s[j];
            if (t->ch.find(x) == t->ch.end()) {
                break;
            }
            len++;
            t = t->ch[x];
        }

        return len;
    }

};

tri tr;

vector<vector<ll>> dp;

ll f(string& s, ll i, vector<ll>& v, bool fl) {
    if (i >= s.size()) {
        if (fl) return 0;
        return -1e16;
    }

    if (dp[i][fl] != -1) {
        return dp[i][fl];
    }

    ll ans = -1e16;

    ll vall = f(s, i + 1, v, (fl | 0));
    if (vall != -1e16) ans = max(ans, vall);

    ll len = tr.qr(s, i);

    for (ll j = 1; j <= len && i + j <= s.size(); j++) {
        ll val = f(s, i + j, v, 1);

        if (val != -1e16) {
            ans = max(ans, v[j - 1] + val);
        }
    }

    return  dp[i][fl] = ans;
}

void HHM() {
    ll  n, i, j, m, k;
    cin >> n >> m;

    string a, b; cin >> a >> b;
    vector<ll> v(m); vin(v);

    reverse(all(a));
    for (i = 0; i < n; i++) {
        string x = a.substr(i, n - i);
        tr.ins(x);
    }


    dp.assign(m + 2, vector<ll>(3, -1));
    ll ans = f(b, 0, v, 0);


    if (ans == -1e16) {
        cout << "IMPOSSIBLE"; return;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
