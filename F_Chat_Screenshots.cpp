#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, k; cin >> n >> k;

    map<int, int>mp;
    while (n--) {
        int x, y; cin >> x >> y;
        mp[x]++; mp[y + 1]--;
    }


    int cnt = 0;

    int ans = 0;

    int prev = 0;
    for (auto x : mp) {
        cnt += x.second;
        if (cnt > 0) {
            ans += x.first - prev;
        }
        prev = x.first;
    }

    cout << ans << endl;
}
