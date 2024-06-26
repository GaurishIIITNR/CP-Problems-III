// // हर हर महादेव

// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace std;
// using namespace __gnu_pbds;

// #define F first
// #define S second
// #define dbl double
// #define pb push_back
// #define ll long long int
// #define uset unordered_set
// #define umap unordered_map
// long long int mod = 1000000007;
// #define all(x) x.begin(), x.end()
// #define Pi 3.1415926535897932384626

// #define vin(v) for(auto &x:v)cin >> x
// #define deb(v) cout << #v << " " << v << "\n"
// #define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
// #define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

// typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n;   vector<pair<ll, ll>>adj[n + 1];
//     ll ans = 0;
//     for (i = 0;i < n - 1; i++) {
//         ll u, v, w; cin >> u >> v >> w;
//         adj[u].pb({ v,w }); adj[v].pb({ u,w }); ans += 2 * w;
//     }
//     ll inf = 1e18;
//     vector<ll>dis(n + 1, inf); dis[1] = 0; dis[0] = 0;

//     priority_queue<ll> pq; pq.push(1);
//     while (pq.size()) {
//         ll node = pq.top(); pq.pop();
//         for (auto x : adj[node]) {
//             if (dis[x.first] > dis[node] + x.S) {
//                 dis[x.first] = dis[node] + x.S;
//                 pq.push(x.first);
//             }
//         }
//     }

//     ll mx = *max_element(all(dis));
//     ans -= mx;
//     cout << ans << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     ll t = 1;
//     // cin >> t;
//     while (t--) { HHM(); }
// }
// // freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<int> getMeanRankCount(vector<int> rank) {
    unordered_map<int, int> mp;
    for (int i = 0; i < rank.size(); i++) {
        int sm = 0;
        for (int j = i; j < rank.size(); j++) {
            sm += rank[j];
            if (sm % (j - i + 1) == 0)
                mp[sm / (j - i + 1)]++;
        }
    }
    vector<int>ans;
    for (int i = 1; i <= rank.size(); i++) {
        ans.push_back(mp[i]);
    }
    return ans;
}

int main() {
    vector<int> rank = { 1, 2, 3, 4, 5 };
    vector<int> ans = getMeanRankCount(rank);
    for (auto x : ans) {
        cout << x << " ";
    }
}
