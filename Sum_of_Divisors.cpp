#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;

    vector<int> a(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            a[j] += i;
        }
    }

    int sm = 0;
    for (int i = 1; i <= n; i++) {
        sm += a[i]; sm %= mod;
    }

    cout << sm;
    return 0;
}



