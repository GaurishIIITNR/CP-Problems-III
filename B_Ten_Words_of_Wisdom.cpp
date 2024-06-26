#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll t; cin >> t; while (t--) {
        ll n; cin >> n; ll mx = -1, mxv = -1; for (int i = 0;i < n;i++) {
            ll a, b;cin >> a >> b; if (a <= 10) if (b > mxv) { mxv = b; mx = i + 1; }
        } cout << mx << endl;
    }
    return 0;
}
