// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;cin >> n;
    vector<ll>v(n);
    for (int i = 0;i < n;i++)cin >> v[i];
    if (n < 3) { cout << 0 << endl; }
    else {
        ll d = min(v[0], v[1]);
        ll c = 0;
        if ((abs(v[2] - v[1])) > (abs(v[2] - v[0])))d = v[0];
        else d = v[1];
        ll e = 0;
        for (int i = 2;i < n;i++) {
            c += (abs(d - (v[i] + e)));
            if (d < v[i])e -= (abs(d - v[i]));
            else e += (abs(d - v[i]));

        }
        cout << c << endl;
    }


    return 0;
}