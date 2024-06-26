// हर हर महादेव

#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

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

// typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

struct node {
    node* ch[26];
    bool end = false;
    node() {
        for (int i = 0; i < 26; i++) ch[i] = NULL;
    }
};

struct trie {
    node* root;
    ll ans = 0;
    trie() {
        root = new node();
    }

    void insert(string& s, ll k, string& mp) {
        node* curr = root;
        ll cnt = 0;
        for (ll i = 0; i < s.size(); i++) {
            if (curr->ch[s[i] - 'a'] == NULL) {
                curr->ch[s[i] - 'a'] = new node(); ans++;
            }
            curr = curr->ch[s[i] - 'a'];
        }
        curr->end = true;
    }
};


void HHM() {
    string a, mp; cin >> a >> mp;
    ll k; cin >> k;

    trie t;

    for (ll i = 0; i < a.size(); i++) {
        string s = ""; int cnt = 0;
        for (ll j = i; j < a.size(); j++) {
            if (mp[a[j] - 'a'] == '0') cnt++;
            if (cnt > k) break;
            s += a[j];
        }
        t.insert(s, k, mp);
    }

    cout << t.ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
