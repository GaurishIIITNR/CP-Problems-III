#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll t; cin >> t; while (t--) {
        ll a, b, c; cin >> a >> b >> c;
        if (a + b >= 10 | b + c >= 10 | c + a >= 10) cout << "Yes" << endl; else 
            cout << "No" << endl;
    }
    return 0;
}
