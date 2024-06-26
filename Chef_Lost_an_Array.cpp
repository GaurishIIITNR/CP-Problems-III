// // // हर हर महादेव

// // #include <bits/stdc++.h>
// // #include <ext/pb_ds/tree_policy.hpp>
// // #include <ext/pb_ds/assoc_container.hpp>

// // using namespace std;
// // using namespace __gnu_pbds;

// // #define F first
// // #define S second
// // #define dbl double
// // #define pb push_back
// // #define int long long int
// // #define uset unordered_set
// // #define umap unordered_map
// // long long int mod = 1000000007;
// // #define aint(x) x.begin(), x.end()
// // #define Pi 3.1415926535897932384626

// // #define vin(v) for(auto &x:v)cin >> x
// // #define deb(v) cout << #v << " " << v << "\n"
// // #define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
// // #define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

// // typedef tree<long long int, nuint_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// // typedef tree<long long int, nuint_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

// // void HHM() {
// //     int  n, i, j, k;
// //     cin >> n >> k;

// //     vector<int>a(n), b(n);
// //     vin(a); vin(b);

// //     vector<pair<int, int>>ans(n);

// //     if (a[0] != b[0]) {
// //         cout << "NO" << endl; return;
// //     }

// //     int mx = a[0], mn = b[0];
// //     ans[0] = { a[0], a[0] };

// //     for (i = 1; i < n; i++) {

// //         if (mx != a[i] && mn != b[i]) {
// //             cout << "NO" << endl; return;
// //         }
// //         if (a[i] == mx && b[i] == mn) {
// //             ans[i] = { max(a[i], ans[i - 1] - k), min(b[i], ans[i - 1] + k) };
// //         }
// //         else if (mx == a[i]) {
// //             ans[i] = {}
// //         }
// //         else {
// //             ans[i] = a[i];
// //         }

// //         mn = b[i], mx = a[i];
// //     }

// //     for (i = 1; i < n; i++) {
// //         if (abs(ans[i] - ans[i - 1]) > k) {
// //             cout << "NO" << endl; return;
// //         }
// //     }

// //     cout << "YES" << endl;
// //     vout(ans);

// // }

// // int main() {
// //     ios_base::sync_with_stdio(0), cin.tie(0);
// //     // freopen("input.txt", "r", stdin); 
// //     // freopen("output.txt", "w", stdout);
// //     int t = 1;
// //     cin >> t;
// //     while (t--) { HHM(); }
// // }



// #include <bits/stdc++.h>
// using namespace std;

// void dfs(vector<int>* adj, int src, int par, vector<int>& lev, int cnt) {
//     lev[src] = cnt; cnt++;
//     for (auto x : adj[src]) {
//         if (x != par) {
//             dfs(adj, x, src, lev, cnt);
//         }
//     }
//     return;
// }

// vector<int>minsignal(string s) {
//     int n = s.length();
//     vector<int>adj[n];

//     for (int i = 0; i < n; i++) {
//         if (s[i] == '0') continue;
//         else {
//             if (s[i] == '1') {
//                 if ((2 * i) + 1 < n && s[(2 * i) + 1] == '1') {
//                     adj[i].push_back((2 * i) + 1);
//                     adj[(2 * i) + 1].push_back(i);
//                 }
//                 if ((2 * i) + 2 < n && s[(2 * i) + 2] == '1') {
//                     adj[i].push_back((2 * i) + 2);
//                     adj[(2 * i) + 2].push_back(i);
//                 }
//             }
//         }
//     }

//     vector<int>lev(n, 0);

//     int leaf = 0, mx = 0;
//     dfs(adj, 0, -1, lev, 0);

//     for (int i = 0; i < n; i++) {
//         if (mx < lev[i]) {
//             mx = lev[i];
//             leaf = i;
//         }
//     }

//     lev.clear();
//     lev.resize(n, 0);

//     dfs(adj, leaf, -1, lev, 0);

//     int leaf2 = 0; mx = 0;
//     for (int i = 0; i < n; i++) {
//         if (mx < lev[i]) {
//             mx = lev[i]; leaf2 = i;
//         }
//     }

//     vector<int>lev1(n, 0);
//     dfs(adj, leaf2, 0, lev1, 0);

//     for (int i = 0;i < n; i++) {
//         lev[i] = max(lev[i], lev1[i]);
//     }

//     return lev;
// }


// int main() {
//     string s; cin >> s;
//     vector<int>ans = minsignal(s);
//     for (auto& x : ans) {
//         cout << x << " ";
//     }
//     cout << endl;
// }


#include <bits/stdc++.h>
using namespace std;


void dfs(vector<int>* adj, int src, int par, vector<int>& lev, int cnt) {
    lev[src] = cnt; cnt++;
    for (auto x : adj[src]) {
        if (x != par) {
            dfs(adj, x, src, lev, cnt);
        }
    }
}

vector<int> f(vector<int>* adj, int n) {
    int i, j, k;

    vector<int>lev(n + 1, 0);
    int leaf = 0, mx = 0; dfs(adj, 1, 0, lev, 0);
    for (i = 1; i <= n; i++) {
        if (mx < lev[i]) {
            mx = lev[i]; leaf = i;
        }
    }

    lev.clear(); lev.resize(n + 1, 0);
    dfs(adj, leaf, 0, lev, 0);
    int leaf2 = 0; mx = 0;  for (i = 1; i <= n; i++) {
        if (mx < lev[i]) {
            mx = lev[i]; leaf2 = i;
        }
    }

    vector<int>lev1(n + 1, 0);
    dfs(adj, leaf2, 0, lev1, 0);

    for (i = 1; i <= n; i++) {
        lev[i] = max(lev[i], lev1[i]);
    }

    return lev;
}

vector<int> minsignal(string s) {
    int n = s.length();
    vector<int> adj[n + 2];

    map<int, bool>mp;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        else {
            if (s[i] == '1') {
                mp[i + 1] = true;
                if ((2 * i) + 1 < n && s[(2 * i) + 1] == '1') {
                    adj[i].push_back((2 * i) + 2);
                    adj[(2 * i) + 2].push_back(i + 1);
                }
                if ((2 * i) + 2 < n && s[(2 * i) + 2] == '1') {
                    adj[i].push_back((2 * i) + 2);
                    adj[(2 * i) + 2].push_back(i);
                }
            }
        }
    }

    vector<int>p = f(adj, n);

    vector<int>res;
    for (auto x : mp) {
        res.push_back(p[x.first]);
    }

    return res;
}

int main() {
    string s; cin >> s;
    vector<int> ans = minsignal(s);
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
