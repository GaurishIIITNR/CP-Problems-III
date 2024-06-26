// // // // हर हर महादेव

// // // #include <bits/stdc++.h>
// // // #include <ext/pb_ds/tree_policy.hpp>
// // // #include <ext/pb_ds/assoc_container.hpp>

// // // using namespace std;
// // // using namespace __gnu_pbds;

// // // #define F first
// // // #define S second
// // // #define dbl double
// // // #define pb push_back
// // // #define ll long long int
// // // #define uset unordered_set
// // // #define umap unordered_map
// // // long long int mod = 1000000007;
// // // #define all(x) x.begin(), x.end()
// // // #define Pi 3.1415926535897932384626

// // // #define vin(v) for(auto &x:v)cin >> x
// // // #define deb(v) cout << #v << " " << v << "\n"
// // // #define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
// // // #define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

// // // typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// // // typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

// // // void HHM() {
// // //     ll  n, i, j, k;
// // //     cin >> n >> k;

// // //     vector<ll>v(n); vin(v);

// // //     ll anything = 0, z = 0;

// // //     bool f = 0;

// // //     for (i = n - 1; i >= 0; i--) {
// // //         if (v[i] > 0) {
// // //             if (i - v[i] < 0) {
// // //                 f = 1; break;
// // //             }
// // //             else if (v[i - v[i]] > 0) {
// // //                 f = 1; break;
// // //             }
// // //             else {
// // //                 v[i - v[i]] = 0;
// // //             }
// // //         }
// // //     }


// // //     for (i = n - 1; i >= 0; i--) {
// // //         if (v[i] > 0) {
// // //             if (i - 1 >= 0 && (v[i - 1] >= 0 && v[i - 1] + 1 != v[i])) {
// // //                 f = 1; break;
// // //             }
// // //             else if (i - 1 >= 0) {
// // //                 v[i - 1] = v[i] - 1;
// // //             }
// // //         }
// // //     }

// // //     for (i = 0; i < n; i++) {
// // //         if (v[i] == 0) z++;
// // //         else if (v[i] == -1) anything++;
// // //     }



// // //     // vout(v);
// // //     // cout << z << " " << anything << endl;
// // //     // cout << f << endl;

// // //     while (k--) {
// // //         ll x; cin >> x;
// // //         if (f) {
// // //             cout << "NO\n";
// // //         }
// // //         else if (x < z) {
// // //             cout << "NO\n";
// // //         }
// // //         else if (x <= (z + anything)) {
// // //             cout << "YES\n";
// // //         }
// // //         else {
// // //             cout << "NO\n";
// // //         }
// // //     }
// // // }

// // // int main() {
// // //     ios_base::sync_with_stdio(0), cin.tie(0);
// // //     // freopen("input.txt", "r", stdin); 
// // //     // freopen("output.txt", "w", stdout);
// // //     ll t = 1;
// // //     cin >> t;
// // //     while (t--) { HHM(); }
// // // }


// // // #include <bits/stdc++.h>
// // // using namespace std;
// // // #define ll long long 

// // // void solve() {
// // //     int n, m; cin >> n >> m;
// // //     vector<int>a(n), b(m);

// // //     for (int i = 0; i < n; i++) {
// // //         cin >> a[i];
// // //     }
// // //     for (int i = 0;i < m; i++) {
// // //         cin >> b[i];
// // //     }

// // //     int st, end; cin >> st >> end;
// // //     bool f = 0;
// // //     for (int i = 0;i < n; i++) {
// // //         if (st == a[i]) {
// // //             f = 1;
// // //         }
// // //         if (end == a[i] && f) {
// // //             cout << "Yes"; return;
// // //         }
// // //     }

// // //     f = 0;
// // //     for (int i = 0;i < m; i++) {
// // //         if (st == b[i]) {
// // //             f = 1;
// // //         }
// // //         if (end == b[i] && f) {
// // //             cout << "Yes"; return;
// // //         }
// // //     }

// // //     unordered_set<int>s;
// // //     int match = -1;
// // //     for (int i = 0;i < n; i++) {
// // //         s.insert(a[i]);
// // //     }
// // //     for (int i = 0; i < m; i++) {
// // //         if (s.find(b[i]) != s.end()) {
// // //             match = b[i]; break;
// // //         }
// // //     }

// // //     f = 0;
// // //     for (int i = 0;i < n;i++) {
// // //         if (a[i] == st) {
// // //             f = 1;
// // //         }
// // //         if (a[i] == match) {
// // //             break;
// // //         }
// // //     }

// // //     for (int i = m - 1; i >= 0; i--) {
// // //         if (f && b[i] == end) {
// // //             cout << "Yes"; return;
// // //         }
// // //         if (b[i] == match) {
// // //             break;
// // //         }
// // //     }

// // //     f = 0;
// // //     for (int i = 0;i < m;i++) {
// // //         if (b[i] == st) {
// // //             f = 1;
// // //         }
// // //         if (b[i] == match) {
// // //             break;
// // //         }
// // //     }

// // //     for (int i = n - 1; i >= 0; i--) {
// // //         if (f && a[i] == end) {
// // //             cout << "Yes"; return;
// // //         }
// // //         if (a[i] == match) {
// // //             break;
// // //         }
// // //     }
// // //     cout << "No";
// // // }
// // // int main() {
// // //     solve();
// // // }


// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // void solve() {
// // //     int n, m; cin >> n >> m;
// // //     vector<int>a(n), b(m);

// // //     for (auto& x : a) cin >> x;
// // //     for (auto& x : b) cin >> x;



// // // }

// // // int main() {

// // // }

// // #include <bits/stdc++.h> 
// // using namespace std;

// // string solve(int n) {
// //     string cd = "A";

// //     for (int i = 2; i <= n; i++) {
// //         string ncd = "";
// //         char curr = cd[0];
// //         int chcnt = 0;

// //         for (int j = 0; j < cd.length(); j++) {
// //             if (cd[j] == curr) {
// //                 chcnt++;
// //             }
// //             else {
// //                 ncd += to_string(chcnt) + curr;
// //                 curr = cd[j];
// //                 chcnt = 1;
// //             }
// //         }

// //         ncd += to_string(chcnt) + curr;
// //         cd = ncd;
// //     }

// //     return cd;
// // }

// // int main() {
// //     int n; cin >> n;
// //     string ans = solve(n);
// //     cout << ans << endl;
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// // vector<string> f(string A) {
// //     vector<string>ans;
// //     string s = "";
// //     int t = 0;
// //     for (int i = 0;A[i];i++) {
// //         if (A[i] == '{' || A[i] == '[') {
// //             ans.push_back(s);
// //             s = "";
// //             for (int j = 0;j < t;j++) s += "**";
// //             s += A[i];
// //             ans.push_back(s);
// //             t++;
// //             s = "";
// //             for (int j = 0;j < t;j++) s += "**";
// //         }
// //         else if (A[i] == '}' || A[i] == ']') {
// //             ans.push_back(s);
// //             s = "";
// //             t--;
// //             for (int j = 0;j < t;j++) s += "**";
// //             s += A[i];
// //             if (A[i + 1] && A[i + 1] == ',') {
// //                 s += A[i + 1];
// //                 i++;
// //             }
// //             ans.push_back(s);
// //             s = "";
// //             for (int j = 0;j < t;j++) s += "**";
// //         }
// //         else if (A[i] == ',') {
// //             s += A[i];
// //             ans.push_back(s);
// //             s = "";
// //             for (int j = 0;j < t;j++) s += "**";
// //         }
// //         else s += A[i];
// //     }
// //     int flag = 0;
// //     ans.push_back(s);
// //     for (int i = 0;i < ans.size();i++) {
// //         flag = 0;
// //         for (int j = 0;j < ans[i].size();j++) {
// //             if (ans[i][j] != '*') {
// //                 flag = 1; break;
// //             }
// //         }
// //         if (!flag) {
// //             ans.erase(ans.begin() + i);
// //             i--;
// //         }
// //     }

// //     return ans;
// // }


// vector<string> f(string A) {
//     vector<string>ans;
//     string s = "";
//     int t = 0;
//     for (int i = 0;A[i];i++) {
//         if (A[i] == '{' || A[i] == '[') {
//             ans.push_back(s);
//             s = "";
//             for (int j = 0;j < t;j++) s += '\t';
//             s += A[i];
//             ans.push_back(s);
//             t++;
//             s = "";
//             for (int j = 0;j < t;j++) s += '\t';
//         }
//         else if (A[i] == '}' || A[i] == ']') {
//             ans.push_back(s);
//             s = "";
//             t--;
//             for (int j = 0;j < t;j++) s += '\t';
//             s += A[i];
//             if (A[i + 1] && A[i + 1] == ',') {
//                 s += A[i + 1];
//                 i++;
//             }
//             ans.push_back(s);
//             s = "";
//             for (int j = 0;j < t;j++) s += '\t';
//         }
//         else if (A[i] == ',') {
//             s += A[i];
//             ans.push_back(s);
//             s = "";
//             for (int j = 0;j < t;j++) s += '\t';
//         }
//         else s += A[i];
//     }
//     int flag = 0;
//     ans.push_back(s);
//     for (int i = 0;i < ans.size();i++) {
//         flag = 0;
//         for (int j = 0;j < ans[i].size();j++) {
//             if (ans[i][j] != '\t' && ans[i][j] != ' ') {
//                 flag = 1; break;
//             }
//         }
//         if (!flag) {
//             ans.erase(ans.begin() + i);
//             i--;
//         }
//     }

//     return ans;
// }

// int main() {
//     string s; getline(cin, s);
//     vector<string>res =f(s);

//     for (auto x : res) {
//         for (auto y : x) {
//             if (y == '\t') cout << "**";
//             else cout << y;
//         }
//         cout << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

void solve() {
    int n, m; cin >> n >> m;
    vector<int>a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0;i < m; i++) {
        cin >> b[i];
    }

    int st, end; cin >> st >> end;
    bool f = 0;
    for (int i = 0;i < n; i++) {
        if (st == a[i]) {
            f = 1;
        }
        if (end == a[i] && f) {
            cout << "Yes"; return;
        }
    }

    f = 0;
    for (int i = 0;i < m; i++) {
        if (st == b[i]) {
            f = 1;
        }
        if (end == b[i] && f) {
            cout << "Yes"; return;
        }
    }

    unordered_set<int>s;
    int match = -1;
    for (int i = 0;i < n; i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++) {
        if (s.find(b[i]) != s.end()) {
            match = b[i]; break;
        }
    }

    f = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] == st) {
            f = 1;
        }
        if (a[i] == match) {
            break;
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        if (f && b[i] == end) {
            cout << "Yes"; return;
        }
        if (b[i] == match) {
            break;
        }
    }

    f = 0;
    for (int i = 0;i < m;i++) {
        if (b[i] == st) {
            f = 1;
        }
        if (b[i] == match) {
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (f && a[i] == end) {
            cout << "Yes"; return;
        }
        if (a[i] == match) {
            break;
        }
    }
    cout << "No";
}
int main() {
    solve();
}