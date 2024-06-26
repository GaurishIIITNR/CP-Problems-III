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
// #define vin(v) for(auto &z: v)cin >> z

// typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
// typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

// #ifndef ONLINE_JUDGE
// #include "debug.h"
// using namespace debug;
// #else 
// #define deb(x)
// #endif



// void HHM() {
//     ll  n, i, j, k;
//     cin >> n >> k;

//     if (n == k) {
//         cout << 0 << endl;
//         return;
//     }

//     vector<pair<ll, ll>> ans;

//     if (n == 0) {
//         ll res = 0;

//         for (i = 63; i >= 0; i--) {
//             if ((k >> i) & 1) {
//                 res = (1LL << i);
//                 break;
//             }
//         }

//         ans.pb({ 0, res });
//         deb(res);
//         n = res;
//     }


//     ll res = 0;

//     for (i = 63; i >= 0; i--) {
//         if ((n >> i) & 1) {
//             res = (1LL << i);
//             break;
//         }
//     }

//     if (res != n) {
//         res *= 2;
//         ll diff = res - n;

//         bitset<64> b = diff;
//         for (i = 0; i < 64; i++) {
//             if (b[i]) {
//                 ans.pb({ n, n + (1LL << i) });
//                 n += (1LL << i);
//             }
//         }
//     }

//     while (2 * n < k) {
//         ans.pb({ n, n * 2 });
//         n *= 2;
//     }

//     ll diff = k - n;

//     bitset<64> b = diff;

//     for (i = 63; i >= 0; i--) {
//         if (b[i]) {
//             ans.pb({ n, n + (1LL << i) });
//             n += (1LL << i);
//         }
//     }


//     cout << ans.size() << endl;
//     for (auto x : ans) {
//         cout << x.F << " " << x.S << endl;
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

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int uniform_random(int l, int r) {
    return l + rand() % (r - l + 1);
}


int ff(vector<int>& v, int tar) {
    int n = v.size();
    int res = INT_MAX;

    for (int i = 0; i < n; i++) {
        int andd = v[i];
        for (int j = i; j < n; j++) {
            andd &= v[j];
            res = min(res, abs(andd - tar));
        }
    }

    return res;
}

int f(vector<int>& v, int tar) {
    int l = 0;
    int ad = -1, n = v.size();
    int res = INT_MAX;

    for (auto& x : v) {
        res = min(res, abs(x - tar));
    }

    vector<int> cnt(32, 0);
    vector<int> a(n, -1);

    for (int i = 0; i < n; i++) {
        a[i] = v[i];
        if (i - 1 >= 0) a[i] &= a[i - 1];

        bitset<32> b = v[i];
        for (int j = 0; j < 32; j++) {
            if (b[j]) {
                cnt[j]++;
            }
        }

        if (a[i] == tar) {
            return 0;
        }

        res = min(res, abs(a[i] - tar));

        while (l < i && tar >= a[i]) {
            if (i - 1 >= l)res = min(res, abs(a[i - 1] - tar));
            if (i >= l)res = min(res, abs(a[i] - tar));

            bitset<32> b = v[l];

            for (int j = 0; j < 32; j++) {
                if (b[j]) {
                    cnt[j]--;
                    if (cnt[j] == i - l) {
                        a[i] |= (1 << j);
                        if (i - 1 >= l) a[i - 1] |= (1 << j);
                    }
                }
            }

            if (i - 1 >= l)res = min(res, abs(a[i - 1] - tar));
            if (i >= l)res = min(res, abs(a[i] - tar));

            l++;
        }
    }

    return res;
}

int main() {
    int t = 100;

    while (t--) {
        int n = uniform_random(1, 100);
        int tar = uniform_random(0, 100);
        vector<int> v(n);

        for (auto& x : v) {
            x = uniform_random(0, 100);
        }

        if (f(v, tar) != ff(v, tar)) {
            cout << "Failed" << endl;
            cout << n << " " << tar << endl;
            for (auto x : v) {
                cout << x << " ";
            }
            cout << endl;
            cout << f(v, tar) << " " << ff(v, tar) << endl;
            break;
        }
    }
}
