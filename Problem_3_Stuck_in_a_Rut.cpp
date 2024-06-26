#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> vp;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        char ch; int x, y; cin >> ch >> x >> y;
        vp.push_back({ x, y });

        if (ch == 'N')  v.push_back(0);
        else v.push_back(1);
    }

    vector<int> ans(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j]) {
                if (v[i] && vp[i].second == vp[j].second && vp[i].first < vp[j].first) {
                    ans[i] = min(ans[i], vp[j].first - vp[i].first);
                }
                else if (!v[i] && vp[i].first == vp[j].first && vp[i].second < vp[j].second) {
                    ans[i] = min(ans[i], vp[j].second - vp[i].second);

                }
            }
            else {
                if (v[i] && vp[i].second < vp[j].second && vp[i].first > vp[j].first) {
                    ans[i] = min(ans[i], vp[i].first - vp[j].first);
                }
                else if (!v[i] && vp[i].first < vp[j].first && vp[i].second > vp[j].second) {
                    ans[i] = min(ans[i], vp[i].second - vp[j].second);
                }
            }
        }
    }
    for (auto x : ans) {
        if (x == INT_MAX) cout << "Infinity\n";
        else cout << x << endl;
    }
}

