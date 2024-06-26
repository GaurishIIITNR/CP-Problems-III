#include <bits/stdc++.h>
using namespace std;
#define ll int 

int main() {
    ll n, k; cin >> n >> k;

    vector<vector<ll>>v(n, vector<ll>(k, 0));
    for (auto& x : v)for (auto& y : x)cin >> y;

    for (int bit = 0; bit < 11; bit++) {

        vector<int>ans(n);
        int both = 0, one = 0, zero = 0;

        for (int i = 0; i < n; i++) {
            int orr = false, andd = true;
            for (int j = 0; j < k; j++) {
                int ith_bit = (v[i][j] >> bit) & 1;
                orr |= ith_bit;
                andd &= ith_bit;
            }
            if (orr ^ andd)both++, ans[i] = 2;
            else if (orr)one++, ans[i] = 1;
            else zero++, ans[i] = 0;
        }

        // cout << bit << " " << one << " " << zero << " " << both << endl;

        if (both == 0 && one % 2 == 0) continue;

        if (one % 2) both = 0;
        else both = 1;

        cout << "TAK\n";
        // for (auto x : ans)cout << x << " "; cout << endl;

        for (int i = 0; i < n; i++) {
            if (ans[i] == 1) {
                cout << 1 << " "; continue;
            }
            if (ans[i] == 0) {
                cout << 1 << " "; continue;
            }
            for (int j = 0; j < k; j++) {
                if (both == 0) {
                    if (!(v[i][j] & (1 << bit))) {
                        cout << j + 1 << " "; break;
                    }
                }
                else {
                    if (v[i][j] & (1 << bit)) {
                        both--;
                        cout << j + 1 << " "; break;
                    }
                }
            }
        }
        cout << endl; return 0;
    }
    cout << "NIE\n"; return 0;
}
