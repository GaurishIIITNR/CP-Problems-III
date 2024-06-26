#include <bits/stdc++.h>
using namespace std;
#define ll int 

int main() {
    string s; cin >> s;
    string p; cin >> p;

    vector<ll> lps(p.size(), 0);

    for (ll i = 1; i < p.size(); i++) {
        ll j = lps[i - 1];
        while (j > 0 && p[i] != p[j]) j = lps[j - 1];

        if (p[i] == p[j]) {
            lps[i] = ++j;
        }
    }

    ll j = 0, cnt = 0;
    for (ll i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = lps[j - 1];
        if (s[i] == p[j]) {
            j++;
        }

        if (j == p.size()) {
            cnt++;
            j = lps[j - 1];
        }
    }

    cout << cnt << endl;
}
