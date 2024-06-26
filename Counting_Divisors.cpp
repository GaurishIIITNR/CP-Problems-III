#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;

    vector<int> a(1e6 + 2, 0);

    for (int i = 1; i <= 1e6 + 1; i++) {
        for (int j = i; j < 1e6 + 2; j += i) {
            a[j]++;
        }
    }

    while (t--) {
        int n; cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}
