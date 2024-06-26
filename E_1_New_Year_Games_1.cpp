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


// class DSU {
//     public:
//     vector<ll>par, anss, rank, sm, sz;
//     ll n;
//     DSU(ll n, vector<ll>& v) {
//         this->n = n;
//         par.assign(n + 1, -1);
//         anss.assign(n + 1, 0);
//         rank.assign(n + 1, 1);
//         sm = v;
//         sz.assign(n + 1, 1);
//     }

//     ll findPar(ll node) {
//         if (par[node] == -1) return node;
//         return findPar(par[node]);
//     }

//     void UnionByRank(ll u, ll v) {
//         ll pu = findPar(u);
//         ll pv = findPar(v);
//         if (pu == pv) return;

//         if (rank[pu] == rank[pv]) {
//             rank[pu]++;
//             sm[pu] += sm[pv];
//             sz[pu] += sz[pv];
//             par[pv] = pu;
//             anss[pv] -= anss[pu];
//         }
//         else if (rank[pu] > rank[pv]) {
//             sm[pu] += sm[pv];
//             sz[pu] += sz[pv];
//             par[pv] = pu;
//             anss[pv] -= anss[pu];
//         }
//         else {
//             sm[pv] += sm[pu];
//             sz[pv] += sz[pu];
//             par[pu] = pv;
//             anss[pu] -= anss[pv];
//         }  return;
//     }

//     ll get(ll node) {
//         if (node == -1) return 0;
//         ll ans = anss[node];
//         ans += get(par[node]);
//         return ans;
//     }
// };

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n >> k;

//     vector<ll>vv(n + 1);
//     for (i = 1; i <= n; i++)cin >> vv[i];

//     DSU d(n + 1, vv);

//     for (i = 0; i < k; i++) {
//         ll u, v; cin >> u >> v;

//         ll uu = d.findPar(u);
//         ll vv = d.findPar(v);
//         if (uu == vv) continue;

//         ll smu = d.sm[uu];
//         ll smv = d.sm[vv];
//         ll szu = d.sz[uu];
//         ll szv = d.sz[vv];

//         if ((smu / szu) > (smv / szv)) {
//             d.anss[uu] += 1;
//         }

//         else if ((smu / szu) < (smv / szv)) {
//             d.anss[vv] += 1;
//         }
//         d.UnionByRank(u, v);
//     }


//     for (i = 1; i <= n; i++) {
//         cout << d.get(i) << " ";
//     }

// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     // freopen("input.txt", "r", stdin); 
//     // freopen("output.txt", "w", stdout);
//     ll t = 1;
//     // cin >> t;
//     while (t--) { HHM(); }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 

// int main() {
//     string s; cin >> s;
//     map<string, string> mp;

//     bool f = 0;
//     string key = "", value = "";
//     int cnt = 0;

//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == '?' && f == 0) {
//             f = 1; continue;
//         }
//         if (f) {
//             if (s[i] == '&') {
//                 mp[key] = value; key = "";
//                 value = ""; cnt = 0;
//             }
//             else if (s[i] == '=') {
//                 cnt++; cnt %= 2;
//             }
//             else if (cnt & 1) value += s[i];
//             else key += s[i];
//         }
//     }

//     if (key != "") mp[key] = value;
//     int q; cin >> q;

//     while (q--) {
//         string par; cin >> par;
//         if (mp.find(par) != mp.end()) {
//             cout << mp[par] << endl;
//         }
//         else cout << -1 << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

vector<string> f(string A) {
    vector<string>ans;
    string s = "";
    int t = 0;
    for (int i = 0;A[i];i++) {
        if (A[i] == '{' || A[i] == '[') {
            ans.push_back(s);
            s = "";
            for (int j = 0;j < t;j++) s += "**";
            s += A[i];
            ans.push_back(s);
            t++;
            s = "";
            for (int j = 0;j < t;j++) s += "**";
        }
        else if (A[i] == '}' || A[i] == ']') {
            ans.push_back(s);
            s = "";
            t--;
            for (int j = 0;j < t;j++) s += "**";
            s += A[i];
            if (A[i + 1] && A[i + 1] == ',') {
                s += A[i + 1];
                i++;
            }
            ans.push_back(s);
            s = "";
            for (int j = 0;j < t;j++) s += "**";
        }
        else if (A[i] == ',') {
            s += A[i];
            ans.push_back(s);
            s = "";
            for (int j = 0;j < t;j++) s += "**";
        }
        else s += A[i];
    }
    int flag = 0;
    ans.push_back(s);
    for (int i = 0;i < ans.size();i++) {
        flag = 0;
        for (int j = 0;j < ans[i].size();j++) {
            if (ans[i][j] != '*' ) {
                flag = 1; break;
            }
        }
        if (!flag) {
            ans.erase(ans.begin() + i);
            i--;
        }
    }

    return ans;
}

int main() {
    string s; getline(cin, s);
    vector<string>res = f(s);
    for (auto x : res) {
        cout << x << endl;
    }
}

