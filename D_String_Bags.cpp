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

struct node {
    node* ch[26];
    bool end = false;
    node() {
        for (int i = 0; i < 26; i++) ch[i] = NULL;
    }
};


struct tri {
    node* root;
    tri() {
        root = new node();
    }

    void insert(string s) {
        node* cur = root;
        for (auto x : s) {
            if (cur->ch[x - 'a'] == NULL) {
                cur->ch[x - 'a'] = new node();
            }
            cur = cur->ch[x - 'a'];
        }
        cur->end = true;
    }

    vector<ll> qr(string& s, ll i) {
        vector<ll> idx;
        node* curr = root;

        for (ll j = i; j < s.size(); j++) {
            if (curr->ch[s[j] - 'a'] == NULL) break;
            curr = curr->ch[s[j] - 'a'];
            if (curr->end) idx.pb(j);
        }

        return idx;
    }
};

vector<vector<ll>> dp;

ll f(ll i, string& s, ll j, vector<tri>& a) {

    if (j == s.size()) return 0;
    if (i == a.size()) {
        return 1e9;
    }

    if (dp[i][j] != -1) return dp[i][j];


    // not take
    ll res = f(i + 1, s, j, a);

    // take
    vector<ll> idx = a[i].qr(s, j);
    for (auto x : idx) {
        res = min(res, 1 + f(i + 1, s, x + 1, a));
    }

    return dp[i][j] = res;
}

void HHM() {
    ll  n, i, j, k;
    string s; cin >> s;
    n = s.size();

    cin >> k;
    vector<tri> a(k);

    for (i = 0;i < k; i++) {
        ll ts; cin >> ts;
        tri t;

        while (ts--) {
            string ss; cin >> ss;
            t.insert(ss);
        }

        a[i] = t;
    }

    dp.assign(k + 1, vector<ll>(n + 1, -1));

    ll ans = f(0, s, 0, a);
    if (ans == 1e9) ans = -1;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    while (t--) { HHM(); }
}
