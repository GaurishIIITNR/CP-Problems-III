// हर हर महादेव 

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
long long int mod = 1000000007;

ll fast(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



void HHM() {
    ll  n, i, j, k;
    cin >> k >> n;

    vector<ll> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll ans = 0;

    for (i = 1; i < fast(2, n); i++) {
        ll lcm = 1;
        bitset<20> b = i;
        for (j = 0; j < n; j++) {
            if (b[j]) {
                lcm = lcm * v[j] / __gcd(lcm, v[j]);
            }
        }
        if (b.count() % 2) {
            ans += k / lcm;
        }
        else {
            ans -= k / lcm;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
