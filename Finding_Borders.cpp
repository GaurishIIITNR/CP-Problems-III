#include <bits/stdc++.h>
using namespace std;
#define ll int 

int main() {
    string p; cin >> p;
    if (p.size() == 1) {
        cout << 0; return 0;
    }

    vector<ll> lps(p.size(), 0);
    vector<ll> ans;

    for (ll i = 1; i < p.size() - 1; i++) {
        ll j = lps[i - 1];
        while (j > 0 && p[i] != p[j]) j = lps[j - 1];

        if (p[i] == p[j]) {
            lps[i] = ++j;
        }
    }

    ll j = lps[p.size() - 2];
    while (j > 0) {
        if (p.back() == p[j]) {
            ans.push_back(j + 1);
        }
        j = lps[j - 1];
    }
    
    if (p.back() == p[j]) {
        ans.push_back(j + 1);
    }

    sort(ans.begin(), ans.end());

    for (auto x : ans) cout << x << " ";

}
