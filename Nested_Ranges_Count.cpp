#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ll n, i; cin >> n;
    vector<vector<ll>> vp(n);

    vector<ll> a(n, 0), b(n, 0);

    for (i = 0; i < n; i++) {
        vp[i].resize(3);
        cin >> vp[i][0] >> vp[i][1];
        vp[i][2] = i;
    }


    sort(vp.begin(), vp.end(), [&](vector<ll>& a, vector<ll>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
        });


   

}