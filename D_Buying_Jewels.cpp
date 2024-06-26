// हर हर महादेव 

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define dbl double
#define pb push_back
#define ll long long int

vector<ll> res;

bool f(ll n, ll k, vector<ll>& ans) {
    if (k == 0) {
        res = ans;
        return true;
    }

    if (n < k || (ans.size() >= 60)) return false;

    bool ok = false;
    for (ll i = 0; i <= 25 && i < k; i++) {
        if (n % (k - i) != 0) {
            ll p = n / (k - i);
            ans.pb(p);
            if(f(n % p, k - (n / p), ans)) return true;
            ans.pop_back();
        }
    }

    return ok;
}


void HHM() {
    ll  n, i, j, k;

    cin >> n >> k;
    res.clear();

    vector<ll> an;
    bool ok = f(n, k, an);

    if (ok == false) {
        cout << "NO\n"; return;
    }

    cout << "YES\n";

    ll rem = n;

    for (ll x : res) {
        rem %= x;
    }

    if (rem) {
        res.push_back(rem + 1);
    }

    if (res.size() > 60) {
        cout << "NO\n"; return;
    }

    cout << res.size() << "\n";
    for (ll x : res) {
        cout << x << " ";
    }cout << endl;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
