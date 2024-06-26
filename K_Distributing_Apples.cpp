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
#define int long long int
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &z: v)cin >> z
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl


const int N = 2e6 + 1;
const int MOD = 1000000007; // 998244353 
int F[N], iF[N]; // Don't forget to change the value of N. factorial,Inverse Factorial Array
// if you want to use without any mod than mod will be INF 

int fast(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    F[0] = 1;

    for (int i = 1; i < N; ++i)
        F[i] = (F[i - 1] * i) % MOD;

    iF[N - 1] = fast(F[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; --i)
        iF[i] = iF[i + 1] * (i + 1) % MOD;
}

int NCR(int n, int r) {
    if (r > n || r < 0)
        return 0;

    return iF[r] * F[n] % MOD * iF[n - r] % MOD;
}

void HHM() {
    int  n, i, j, k, r;
    cin >> n >> r;
    cout << NCR(n + r - 1, n - 1) << endl;

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;

    init();
    while (t--) { HHM(); }
}
