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

// string f(ll n, ll m, ll k, string s) {
//     ll i, j;

//     vector<vector<ll>>cnt(k, vector<ll>(k, 0));
//     vector<ll> ocr(k, 0);

//     for (i = 0; i < m; i++) {
//         int curr = s[i] - 'a';

//         for (j = 0; j < k; j++) {
//             cnt[curr][j] = ocr[j];
//         }

//         ocr[curr]++;
//     }

//     for (i = 0; i < k; i++) {
//         for (j = 0; j < k; j++) {

//             if (n - 1 > cnt[i][j]) {
//                 string ans = "";
//                 for (ll kk = 0; kk < n; kk++) {
//                     if (kk < n - 1) ans += (char)('a' + j);
//                     else  ans += (char)('a' + i);
//                 }

//                 cout << "NO\n";
//                 return ans;
//             }

//         }

//     }

//     return  "";
// }

// void HHM() {
//     ll  n, i, j, k, m;
//     cin >> n >> k >> m;

//     string s; cin >> s;

//     string res = f(n, m, k, s);

//     if (res == "") {
//         reverse(all(s));
//         string ans = f(n, m, k, s);
//         if (ans == "") {
//             cout << "YES\n"; return;
//         }

//         reverse(all(ans));
//         cout << ans << endl;
//     }
//     else {
//         cout << res << endl; return;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);
//     // freopen("input.txt", "r", stdin); 
//     // freopen("output.txt", "w", stdout);
//     ll t = 1;
//     cin >> t;
//     while (t--) { HHM(); }
// }

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

void HHM() {
    ll  n, i, j, k, m;
    cin >> n >> k >> m;

    string s; cin >> s;

    vector<ll>last(k, -1);
    vector<ll>ocr(k, 0);

    for (i = 0; i < m; i++) {
        int curr = s[i] - 'a';
        last[curr] = i;
        ocr[curr]++;
    }

    set<int>st;
    for (i = 0; i < k; i++) {
        st.insert(last[i]);
        if (ocr[i] < n) {
            cout << "NO\n";
            string ans(n, (char)('a' + i));
            cout << ans << endl;  return;
        }
    }

    ocr.assign(k, 0);
    for (i = 0; i < m; i++) {
        if (st.find(i) != st.end()) {
            for (j = 0; j < k; j++) {
                if (i != j && ocr[j] < n - 1) {
                    cout << "NO\n";
                    string ans(n - 1, (char)('a' + j)); ans += s[i];
                    cout << ans << endl;  return;
                }
            }
        }
        ocr[s[i] - 'a']++;
    }

    last.assign(k, -1);
    ocr.assign(k, 0);

    for (i = m - 1; i >= 0; i--) {
        int curr = s[i] - 'a';
        last[curr] = i;
        ocr[curr]++;
    }

    st.clear();
    for (i = 0; i < k; i++) {
        st.insert(last[i]);
        if (ocr[i] < n) {
            cout << "NO\n";
            string ans(n, (char)('a' + i));
            cout << ans << endl;  return;
        }
    }

    ocr.assign(k, 0);
    for (i = m; i >= 0; i--) {
        if (st.find(i) != st.end()) {
            for (j = 0; j < k; j++) {
                if (i != j && ocr[j] < n - 1) {
                    cout << "NO\n";
                    string ans(n - 1, (char)('a' + j)); ans += s[i];
                    reverse(all(ans));
                    cout << ans << endl;  return;
                }
            }
        }
        ocr[s[i] - 'a']++;
    }

    cout << "YES\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}

