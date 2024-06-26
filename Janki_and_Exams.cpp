// हर हर महादेव

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll t; cin >> t;
    while(t--){
        ll a, b, c; cin >> a >> b >> c;
        ll sm = a + b + c;
        if (sm >= 90) {
            cout << "PASS\n";
        }
        else cout << "FAIL\n";
     }
    return 0;
}
