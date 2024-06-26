#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
using namespace std;

int powMod(ll x, unsigned ll y, ll p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, n;
        cin >> a >> n;
        if (a < 0) {
            cout << 1 << endl;
        }
        else {
            cout << powMod(a, n / 2, MOD) << endl;
        }
    }
    return 0;
}