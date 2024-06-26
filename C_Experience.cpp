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


class DSU {
    public:
    vector<int>par, size, rank;
    int n;
    DSU(int n) {
        this->n = n;
        par.assign(n + 1, -1);
        size.assign(n + 1, 0);
        rank.assign(n + 1, 0);
    }

    int findPar(int node) {
        if (par[node] == -1) return node;
        return findPar(par[node]);
    }

    void UnionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) return;

        if (rank[pu] == rank[pv]) {
            rank[pu]++;
            par[pv] = pu;
            size[pv] -= size[pu];
        }
        else if (rank[pu] > rank[pv]) {
            par[pv] = pu;
            size[pv] -= size[pu];
        }
        else {
            par[pu] = pv;
            size[pu] -= size[pv];
        }  return;
    }

    int get(int node) {
        if (node == -1) return 0;
        ll ans = size[node];
        ans += get(par[node]);
        return ans;
    }
};

void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    DSU x(n);
    while (k--) {
        string s; cin >> s;
        if (s == "join") {
            cin >> i >> j;
            x.UnionByRank(i, j);
        }
        else if (s == "get") {
            cin >> i;
            cout << x.get(i) << endl;
        }
        else {
            cin >> i >> j;
            ll p = x.findPar(i);
            x.size[p] += j;
        }
    }
    // vout(x.par);
    // vout(x.size);
    // vout(x.rank);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
