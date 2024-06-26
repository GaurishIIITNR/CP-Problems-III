#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int dir[4][2] = { {0, 1}, {0, -1}, {1,0}, {-1, 0} };
map<char, int> mp;

bool ok(ll i, int j) {
    return (i >= 0 && i < 7 && j >= 0 && j < 7);
}

ll f(int i, int j, int idx, vector<bool>&vis, string& s) {
    if (idx == 48) return 1;

    ll ans = 0;

    if (s[idx] == '?') {
        
    }
    else {
        int d = mp[s[idx]];
        int ni = i + dir[d][0];
        int nj = j + dir[d][1];

        if (ni >= 0 && ni < 7 && nj >= 0 && nj < 7 && !vis[ni * 7 + nj]) {
            vis[ni * 7 + nj] = 1;
            ans += f(ni, nj, idx + 1, vis, s);
            vis[ni * 7 + nj] = 0;
        }
    }

    return ans;
}

int main() {

    mp['L'] = 0;  mp['R'] = 1; mp['D'] = 2; mp['U'] = 3;

    string s; cin >> s;
    vector<bool> vis(49, 0);

    cout << f(0, 0, 0, vis, s);
}
