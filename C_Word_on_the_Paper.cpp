#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll t; cin >> t; while (t--) {
        ll n = 8; vector<string>v; string tmp = "";  for (int i = 0;i < 8; i++) { string s;  cin >> s;  v.push_back(s); }
        for (int i = 0;i < 8; i++) {
            for (int j = 0;j < 8; j++) {
                if (v[j][i] == '.') continue;
                else tmp += v[j][i];
            }
        } cout << tmp << endl;
    } 
    return 0;
}
