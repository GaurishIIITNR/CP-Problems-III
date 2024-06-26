#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    freopen("shell.in", "r", stdin); freopen("shell.out", "w", stdout);

    ll n; cin >> n;
    array<ll, 3> a;
    vector<tuple<ll, ll, ll>>v(n);

    for (ll i = 0;i < n; i++) {
        ll x, y, z; cin >> x >> y >> z; --x, --y, --z;
        v[i] = { x, y, z };
    }

    ll ans = 0;
    for (ll i = 0;i < 3; i++) {
        a[0] = a[1] = a[2] = 0; a[i] = 1;
        ll c = 0;
        for (auto x : v) {
            ll i1 = get<0>(x), i2 = get<1>(x), i3 = get<2>(x);
            swap(a[i1], a[i2]); if (a[i3]) c++;
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
}

