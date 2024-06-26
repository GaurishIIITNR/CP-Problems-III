#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<ll>> adj;
vector<ll> cmp, dp;

void reset(ll n) {
    adj.assign(n + 1, vector<ll>());
    dp.assign(n + 1, 0);
    cmp.assign(n + 1, 0);
}

ll cmpt(ll src, ll p) {
    ll ans = 0;
    for (auto x : adj[src]) {
        if (x == p) continue;
        ans += cmpt(x, src);
    }
    return cmp[src] = ans + 1;
}

ll f(ll src, ll p) {
    ll ans = 0;

    for (auto x : adj[src]) {
        if (x == p) continue;
        ans += f(x, src);
    }
    dp[src] = ans + cmp[src] - 1;
    return dp[src];

}

void dfs(ll src, ll p) {
    if (p > 0) {
        ll ans = dp[p] - cmp[src] + (cmp.size() - 1) - cmp[src];
        dp[src] = ans;
    }

    for (auto x : adj[src]) {
        if (x == p) continue;
        dfs(x, src);
    }
}



int main() {
    ll n; cin >> n;

    reset(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cmpt(1, 0);
    f(1, 0);
    dfs(1, 0);

    for (ll i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }

}
