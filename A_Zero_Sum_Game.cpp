#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll n; cin >> n;

    ll sm = 0;

    for (ll i = 0; i < n - 1; i++) {
        ll d; cin >> d;
        sm += d;
    }

    cout << -1 * sm;
}
