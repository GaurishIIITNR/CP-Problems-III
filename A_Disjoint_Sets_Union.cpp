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



class dsu {
    public:

    struct node {
        ll par, sz, rank;
        node() {
            par = -1;
            sz = 1;
            rank = 0;
        }
    };

    ll n;
    vector<node> tr;

    dsu(ll n) {
        this->n = n;
        tr.assign(n, node());
    }

    ll findPar(ll u) {
        if (tr[u].par == -1) return u;

        // used path compression
        return tr[u].par = findPar(tr[u].par);
    }

    void UnionByRank(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;

        if (tr[pu].rank == tr[pv].rank) {
            tr[pu].rank++; tr[pv].par = pu;
        }
        else if (tr[pu].rank > tr[pv].rank) tr[pv].par = pu;
        else tr[pu].par = pv;    return;
    }

    void UnionBySz(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;

        if (tr[pu].sz >= tr[pv].sz)tr[pu].sz += tr[pv].sz, tr[pv].par = pu;
        else tr[pv].sz += tr[pu].sz, tr[pu].par = pv;
        return;
    }

    bool get(ll u, ll v) {
        return findPar(u) == findPar(v);
    }

    // ll gett(ll u) {
    //     if (u == -1) return 0;
    //     ll ans = tr[u].sz;
    //     ans += get(tr[u].par);
    //     return ans;
    // }
};

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    dsu x(n);

    for (i = 0; i < k; i++) {
        string s; int u, v; cin >> s >> u >> v;
        if (s == "union") {
            x.UnionBySz(u, v);
        }
        else {
            x.get(u, v) ? cout << "YES\n" : cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
