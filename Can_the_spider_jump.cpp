#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (min(c - d, c - e) >= a) cout << "JUMP" << endl;
        else cout << "FALL" << endl;
    }
    return 0;
}