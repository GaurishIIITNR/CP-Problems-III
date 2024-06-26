#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll, ll>>dp;

pair<ll, ll> f(vector<ll>& v, ll mask, ll k) {
    ll n = v.size();
    if (mask + 1 == (1 << n)) return dp[mask] = { 0, 0 };
    if (dp[mask].first != -1) return dp[mask];

    ll cnt = INT_MAX, left = 0;
    for (ll j = 0; j < n; j++) {
        if (!(mask & (1 << j))) {
            auto r = f(v, (mask | (1 << j)), k);
            ll x = r.first, y = r.second;

            if (x + v[j] > k) {
                x = v[j]; y++;
            }
            else x += v[j];

            if (y < cnt) {
                cnt = y, left = x;
            }

            else if (y == cnt) {
                cnt = y; left = min(left, (ll)x);
            }
        }
    }
    return dp[mask] = { left, cnt };
}

int main() {
    ll n, k; cin >> n >> k;
    vector<ll>v(n);
    for (ll& i : v) cin >> i;
    dp.assign((1 << n) + 1, { -1, -1 });

    auto r = f(v, 0, k);
    ll x = r.first, y = r.second;

    if (x > 0) {
        y++;
    }

    cout << y;
}


