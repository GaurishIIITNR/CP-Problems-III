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
// #define ll int int
// #define uset unordered_set
// #define umap unordered_map
// int int mod = 1000000007;
// #define all(x) x.begin(), x.end()
// #define Pi 3.1415926535897932384626

// #define vin(v) for(auto &x:v)cin >> x
// #define deb(v) cout << #v << " " << v << "\n"
// #define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
// #define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

// typedef tree<int int, null_type, less<int int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// typedef tree<int int, null_type, less_equal<int int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

// class cmp {
//     public:
//     bool operator()(pair<ll, ll>& a, pair<ll, ll>& b) {
//         return a.second > b.second;
//     }
// };

// bool ok(vector<ll> v, vector<ll> d, ll m) {

//     priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> p;
//     multiset<pair<ll, ll>>q;

//     for (ll i = 0; i < v.size(); i++) {

//         // if (p.size() && p.top().second < i) {
//         //     return false;
//         // }

//         if (q.size()) {
//             auto it = q.lower_bound({ i - d[i], 0 });
//             while (it != q.end() && v[i] > 0) {
//                 ll x = it->first; ll y = it->second;
//                 auto nxt = it; nxt++;
//                 if (y > v[i]) {
//                     q.erase(it);
//                     q.insert({ x, y - v[i] });
//                     v[i] = 0;
//                     break;
//                 }
//                 else {
//                     v[i] -= y;
//                     q.erase(it);
//                 }
//                 it = nxt;
//             }
//         }

//         if (v[i] > m) {
//             p.push({ v[i] - m, i + d[i] });
//         }

//         if (v[i] < m) {
//             ll diff = m - v[i];
//             while (diff > 0) {
//                 if (p.size() == 0) {
//                     q.insert({ i,diff });
//                     diff = 0;
//                     break;
//                 }

//                 else {
//                     ll x = p.top().first;
//                     ll y = p.top().second;
//                     p.pop();
//                     if (x > diff) {
//                         p.push({ x - diff, y });
//                         diff = 0;
//                         break;
//                     }
//                     else  diff -= x;
//                 }
//             }
//             if (diff) {
//                 q.insert({ i,diff }); diff = 0;
//             }
//         }
//     }

//     if (p.size()) return false;
//     return true;
// }

// void HHM() {
//     ll  n, i, j, k;
//     cin >> n;
//     vector<ll>v(n); vin(v);
//     vector<ll>door(n); vin(door);

//     ll l = 0, h = (ll)1e9 + 1;

//     while (l < h) {
//         ll m = l + (h - l) / 2;
//         if (ok(v, door, m)) h = m;
//         else l = m + 1;
//     }

//     cout << l << endl;

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
#define ll int 

int sm(int n)
{
    int s = 0;
    while (n) {
        int d = n % 10;
        s += d * d;
        n = n / 10;
    }
    return s;
}

bool happ(int n)
{
    unordered_set<int> s;
    s.insert(n);
    while (1) {
        if (n == 1)
            return true;
        n = sm(n);
        if (s.find(n) != s.end())
            return false;
        s.insert(n);
    }

    return false;
}

int getMaxSizeHappyNumSet(int happyNumLow, int happyNumHigh) {

    unordered_set<string> ans;
    for (int i = happyNumLow;i <= happyNumHigh; i++) {
        if (happ(i)) {
            string s = to_string(i); sort(s.begin(), s.end());
            ans.insert(s);
        }
    }
    return (int)ans.size();
}

int main() {
    int l, r; cin >> l >> r;
    cout << getMaxSizeHappyNumSet(l, r);
    return 0;
}
