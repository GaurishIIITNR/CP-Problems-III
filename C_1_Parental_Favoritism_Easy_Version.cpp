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

struct node {
    ll l, r, val;
    node() {
        l = r = val = 0;
    }
    node(ll l, ll r, ll val) {
        this->l = l; this->r = r; this->val = val;
    }
};

node tr[101];

void build(ll i, ll l, ll r, ll x, ll y, ll prev) {
    if (x == y) {
        tr[i] = node(x, y, prev); return;
    }
    ll mid = (l + r) / 2;
    build(2 * i, l, mid, x, y - 1, 1);
    build((2 * i) + 1, mid + 1, r, x + 1, y, 2);
    tr[i] = node(x, y, prev);
}

ll query(ll i, ll l, ll r, ll l1, ll r1, ll l2, ll r2) {
    if(l)
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;
    string s; cin >> s;


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
