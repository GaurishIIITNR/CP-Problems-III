#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    vector<ll>v;
    ll x;
    while (cin >> x) {
        v.push_back(x);
    }

    ll w = v.back(); v.pop_back();
    sort(v.begin(), v.end());

    ll l = 0, r = v.size() - 1;
    ll ans = 0;

    while (l < r) {
        if (v[l] == 0) {
            l++; continue;
        }
        if (v[l] + v[r] <= w) {
            l++, r--; ans++;
        }
        else {
            r--; ans++;
        }
    }

    if (l == r) ans++;
    cout << ans;
}
