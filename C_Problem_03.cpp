// हर हर महादेव

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define dbl double
#define pb push_back
#define ll long long int
#define uset unordered_set
#define umap unordered_map
ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> sat;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> multisat;

ll dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
ll dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool ok(ll x, ll y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void HHM() {
    ll  n, i, j, k;
    // cin >> n;
    char c, d, e, f; cin >> c >> d >> e >> f;
    ll x = c - 'a', y = d - '1', lx = e - 'a', ly = f - '1';

    vector<vector<ll>> ds(8, vector<ll>(8, -1));
    queue<pair<ll, ll>> q;

    ds[x][y] = 0;
    q.push({ x, y });

    while (!q.empty()) {
        ll x = q.front().first, y = q.front().second; q.pop();

        if (x == lx && y == ly) {
            cout << ds[x][y] << endl; return;
        }

        for (ll i = 0; i < 8; i++) {
            ll nx = x + dx[i], ny = y + dy[i];

            if (ok(nx, ny) && ds[nx][ny] == -1) {
                ds[nx][ny] = ds[x][y] + 1, q.push({ nx, ny });
            }
        }
    }

    cout << -1 << endl;
    return;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
// freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
