#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj, tr, par;
vector<int> fl, lev;
vector<bool> ok;


void dfs(int src, int p) {
    fl.push_back(src);

    for (auto x : adj[src]) {
        if (x != p) dfs(x, src);
    }

    fl.push_back(src);
    return;
}



void build(int i, int s, int e, vector<char>& a) {
    if (s == e) {
        int idx = fl[s]; idx--;
        char c = a[idx];

        if (ok[s] == true) tr[i][c - 'a']--;
        else tr[i][c - 'a']++;

        return;
    }


    int m = s + e; m /= 2;

    build(2 * i, s, m, a);
    build(2 * i + 1, m + 1, e, a);

    for (int j = 0; j < 26; j++) {
        tr[i][j] = tr[2 * i][j] + tr[2 * i + 1][j];
    }

    return;
}

vector<int> query(int i, int s, int e, int l, int r) {
    if (r < s || e < l) {
        vector<int> cnt(26, 0);
        return cnt;
    }

    if (l <= s && e <= r) return tr[i];

    int m = s + e; m /= 2;

    vector<int> a = query(2 * i, s, m, l, r);
    vector<int> b = query(2 * i + 1, m + 1, e, l, r);

    for (int j = 0; j < 26; j++) {
        a[j] += b[j];
    }

    return a;
}

void Blift(int src, int p) {
    par[src][0] = p;
    lev[src] = lev[p] + 1;

    for (int i = 1; i < par[0].size(); i++) {
        par[src][i] = par[par[src][i - 1]][i - 1];
    }

    for (auto x : adj[src]) {
        if (x != p) Blift(x, src);
    }
    return;
}

int kpar(int node, int k) {
    int i = 0;

    while (k) {
        if (k & 1) node = par[node][i];
        k >>= 1; i++;
    }

    return node;
}

int lca(int u, int v) {
    if (lev[u] > lev[v]) u = kpar(u, lev[u] - lev[v]);
    else if (lev[v] > lev[u])  v = kpar(v, lev[v] - lev[u]);

    if (u == v) return u;

    for (int i = par[0].size() - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }

    return par[u][0];
}

string  solve(vector<char>& a, vector<vector<int>>& e, vector<vector<int> >& q) {
    int n = a.size();
    adj.assign(n + 1, vector<int>());
    par.assign(n + 1, vector<int>(20, 0));
    lev.assign(n + 1, 0);

    for (auto x : e) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    dfs(1, 0);

    ok.assign(fl.size(), 0);
    tr.assign(4 * (fl.size()) + 1, vector<int>(26, 0));

    map<int, int> mp;

    for (int i = 0; i < fl.size(); i++) {
        if (mp.find(fl[i]) == mp.end()) {
            mp[fl[i]] = i; ok[i] = false;
        }
        else ok[i] = true;
    }



    Blift(1, 0);
    build(1, 0, (fl.size() - 1), a);

    string res = "";

    for (auto x : q) {
        int lc = lca(x[0], x[1]);

        vector<int> aa = query(1, 0, fl.size() - 1, mp[lc], mp[x[0]]);
        vector<int> bb = query(1, 0, fl.size() - 1, mp[lc], mp[x[1]]);

        aa[a[lc - 1] - 'a']--;

        for (int i = 0; i < 26; i++) {
            aa[i] += bb[i];
        }

        int mn = 0, mnv = aa[0];
        for (int i = 0; i < 26; i++) {
            if (aa[i] > 0 && mnv > aa[i]) {
                mn = i, mnv = aa[i];
            }
        }

        res += (char)(mn + 'a');
    }

    return res;
}

int main() {
    int n; cin >> n;

    vector<char> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> e(n - 1, vector<int>(2, 0));
    for (int i = 0; i < n - 1; i++) {
        cin >> e[i][0] >> e[i][1];
    }

    int q; cin >> q;
    vector<vector<int>> qq(q, vector<int>(2, 0));

    for (int i = 0; i < q; i++) {
        cin >> qq[i][0] >> qq[i][1];
    }

    cout << solve(a, e, qq) << endl;
}