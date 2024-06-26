#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll t; cin >> t;
    while (t--) {
        string s; cin >> s;

        ll a = 0, b = 0;

        for (auto c : s) {
            if (c == 'A') a++;
            else b++;
        }

        if (a > b)cout << "A\n";
        else cout << "B\n";

    }
    return 0;
}
