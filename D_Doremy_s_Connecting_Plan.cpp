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

// class DSU {
//     public:
//     vector<int>parent, size, rank;
//     int n;
//     DSU(int n) {
//         this->n = n;
//         parent.assign(n + 1, -1);
//         size.assign(n + 1, 1);
//         rank.assign(n + 1, 0);
//     }

//     int findPar(int node) {
//         if (parent[node] == -1) return node;
//         return parent[node] = findPar(parent[node]); // used path compression
//     }

//     void UnionByRank(int u, int v) {
//         int pu = findPar(u);
//         int pv = findPar(v);
//         if (pu == pv) return;
//         if (rank[pu] == rank[pv]) {
//             rank[pu]++; parent[pv] = pu;
//         }
//         else if (rank[pu] > rank[pv])parent[pv] = pu;
//         else parent[pu] = pv;    return;
//     }

//     void UnionBySize(int u, int v) {
//         int pu = findPar(u);
//         int pv = findPar(v);
//         if (pu == pv) return;
//         if (size[pu] >= size[pv])size[pu] += size[pv], parent[pv] = pu;
//         else size[pv] += size[pu], parent[pu] = pv;
//         return;
//     }

//     bool get(int u, int v) {
//         return findPar(u) == findPar(v);
//     }
// };


void HHM() {
    ll  n, i, j, k;
    cin >> n >> k;
    vector<ll>v(n);
    ll sm = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (i == 1) {
            sm += x; continue;
        }
        if (i * k <= x) {
            sm += x; continue;
        }
        else  pq.push({ (i * k) - x, x });
    }

    while (pq.size()) {
        // cout << sm << endl;
        // cout << pq.top().first << " " << pq.top().second << endl;
        if (pq.top().first > sm) {
            cout << "No" << endl; return;
        }
        sm += pq.top().second ; pq.pop();
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
