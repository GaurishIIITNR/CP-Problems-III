#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    // looks like grid chossing path from one cell to another
    // n = x + y, x - y = 0; and constrain the path upper the diagonal

    ll n; cin >> n;

    if (n % 2) {
        cout << 0; return 0;
    }

    // want that Nc(N/2) if no constrain
    // tot ways = #[(0, 0) -> (N, 0)] - #[(-2, 0) -> (N, 0)]


    for (ll i = 0; i < 10; i++) {
        cout << F[i] << " " << iF[i] << " " << iFF[i] << endl;
    }

}
