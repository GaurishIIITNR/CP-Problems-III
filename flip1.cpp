#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll f(vector<vector<ll>>& v, ll i, ll j, vector<vector<pair<ll, ll>>>& dp) {
    ll mxi = -1, mxj = -1, ans = 0;
    if (i + 1 < v.size()) {
        ans = f(v, i + 1, j, dp); mxi = i + 1, mxj = j;
        if (j + 1 < v[0].size()) {
            ll temp = f(v, i + 1, j + 1, dp);
            if (ans < temp) {
                ans = temp;
                mxi = i + 1, mxj = j + 1;
            }
        }
        if (j - 1 >= 0) {
            ll  temp = f(v, i + 1, j - 1, dp);
            if (ans < temp) {
                ans = temp;
                mxi = i + 1, mxj = j - 1;
            }
        }
    }

    dp[i][j] = { mxi,mxj };
    ans += v[i][j];
    return ans;

}

int main() {

    ll n, m; cin >> n >> m;
    vector<vector<ll>>v(n, vector<ll>(m));
    for (ll i = 0; i < n;i++)
        for (ll j = 0; j < m; j++)
            cin >> v[i][j];

    
    vector<vector<pair<ll, ll>>>dp(n, vector<pair<ll, ll>>(m, { -1,-1 }));
    ll ans = f(v, 0, 0, dp);

    ll i = 0, j = 0;
    while (i != -1 && j != -1) {
        v[i][j] = 0;
        auto p = dp[i][j];
        i = p.first;
        j = p.second;
    }

    ans += f(v, 0, m - 1, dp);
    cout << ans << endl;
}
