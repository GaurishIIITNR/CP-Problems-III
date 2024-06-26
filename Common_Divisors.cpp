#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<int>a(1e6 + 2, 0);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mx = max(mx, x); a[x]++;
    }

    for (int i = mx; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= mx; j += i) {
            cnt += a[j];
        }

        if (cnt > 1) {
            cout << i << endl; return 0;
        }
    }

    return 0;
}
