// हर हर महादेव

#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll>tr;

void build(vector<ll>& v, int id, int l, int r, int m) {
    if (l == r) {
        tr[id] = v[l] % m;
        return;
    }

    int mid = (l + r) / 2;
    build(v, 2 * id, l, mid, m);
    build(v, 2 * id + 1, mid + 1, r, m);

    tr[id] = (tr[2 * id] * tr[2 * id + 1]) % m;
}

ll query(int id, int l, int r, int ql, int qr, int m) {
    if (ql > r || qr < l) return 1;
    if (ql <= l && qr >= r) return tr[id] % m;

    int mid = (l + r) / 2;
    ll lf = query(2 * id, l, mid, ql, qr, m); lf %= m;
    ll rt = query(2 * id + 1, mid + 1, r, ql, qr, m);  rt %= m;

    return (lf * rt) % m;
}

int main() {
    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;

        vector<ll> v(n);
        for (auto& x : v) cin >> x;

        string s; cin >> s;

        tr.assign((4 * n) + 1, 1);
        build(v, 1, 0, n - 1, m);

        int l = 0, h = n - 1;
        cout << query(1, 0, n - 1, l, h, m) << " ";

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'R') h--;
            else l++;
            cout << query(1, 0, n - 1, l, h, m) << " ";
        }

        cout << endl;

    }
    return 0;
}
