#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>>v(n, vector<ll>(m));
    for (ll i = 0; i < n;i++)
        for (ll j = 0; j < m; j++)
            cin >> v[i][j];

    vector<vector<int>>cnt(n);
    for (int j = 0; j < m; j++) {
        ll mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, v[i][j]);
        }
        for (int i = 0; i < n; i++) {
            if (v[i][j] == mx) {
                cnt[i].push_back(v[i][j]);
            }
        }
    }

    ll mxcnt = 0;
    for (int i = 0;i < n; i++) {
        mxcnt = max((ll)cnt[i].size(), mxcnt);
    }

    ll ans_id = -1, ans_sm = 0;
    for (int i = 0;i < n;i++) {
        if (cnt[i].size() == mxcnt) {
            ll sm = 0;
            for (auto x : cnt[i]) {
                sm += x;
            }
            if (ans_sm < sm) {
                ans_sm = sm;
                ans_id = i;
            }
        }
    }

    cout << ans_id  << " " << mxcnt << endl;
}
