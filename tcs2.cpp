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

vector<vector<ll>> adj;
vector<bool>vis;
vector<ll>path;

void reset(ll n) {
    adj.assign(n + 1, vector<ll>());
    vis.assign(n + 1, false);
    path.assign(n + 1, -1);
}

ll cnv(string s) {
    if (s == "Start" || s == "End") return -1;
    if (s[0] == 'S' || s[0] == 'L') {
        ll n = s.size();
        string tmp = "";
        for (ll i = 2; i < n - 1; i++) {
            tmp += s[i];
        }
        if (tmp == "Start") return 1;
        if (tmp == "End") return 100;
        // cout << tmp << endl;
        return stoll(tmp);
        // return -1;
    }
    return -1;
}


void HHM() {

    reset(100);

    ll st = 100, i;

    while (st > 0) {
        string s;
        for (i = 0; i < 10;i++) {
            cin >> s;
            // cout << cnv(s) << " ";
            if (cnv(s) > 0) {
                adj[st].pb(cnv(s));
            }
            st--;
        }
        // cout << endl;
        st -= 9;
        for (i = 0; i < 10; i++) {
            cin >> s;
            // cout << cnv(s) << " ";
            if (cnv(s) > 0) {
                adj[st].pb(cnv(s));
            }
            st++;
        }
        // cout << endl;
        st -= 11;
    }

    vector<ll>v;
    ll n;
    while (cin >> n) {
        v.pb(n);
    }

    ll src = 0, sn = 0, ld = 0;
    for (auto x : v) {
        src += x;
        while (1) {
            if (adj[src].size() == 0) break;
            if (src > adj[src][0]) sn++;
            else ld++;
            src = adj[src][0];
        }
        if (src == 100) {
            cout << "Possible" << " " << sn << " " << ld;
            return;
        }
    }
    if (src == 0 || src == 1) {
        cout << "Not possible " << sn << " " << ld << " " << "Start"; return;
    }
    cout << "Not possible " << sn << " " << ld << " " << src;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
