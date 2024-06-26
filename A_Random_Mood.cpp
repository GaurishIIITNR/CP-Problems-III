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
long long int mod = 1000000007;
#define all(x) x.begin(), x.end()
#define Pi 3.1415926535897932384626

#define vin(v) for(auto &x:v)cin >> x
#define deb(v) cout << #v << " " << v << "\n"
#define vout(v) for(auto x:v)cout << x << " " ;cout<<endl
#define deb2(v, k) cout << #v << " " << v << "\n" \<< #k << " " << k << "\n"

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;

class matrixExpo {
    public:
    ll k; // dependent on previous k terms
    vector<vector<dbl>> base, tr; // base case matrix and transformation matrix

    matrixExpo(ll k) {
        this->k = k;
        tr.assign(k, vector<dbl>(k, 0)); // k X k matrix
        base.assign(1, vector<dbl>(k, 0)); // k X 1 matrix
    }

    // matrix multiplication
    vector<vector<dbl>> mul(vector<vector<dbl>>& a, vector<vector<dbl>>& b) {
        vector<vector<dbl>>res(a.size(), vector<dbl>(b[0].size(), 0));

        for (int i = 0; i < a.size(); i++) {
            for (int k = 0; k < b[0].size(); k++) {
                for (int j = 0; j < a[0].size(); j++) {
                    res[i][k] += a[i][j] * b[j][k];
                }
            }
        }

        return res;
    }

    // binary exponentiation
    vector<vector<dbl>> binpow(vector<vector<dbl>>& tr, ll n) {

        vector<vector<dbl>>res(k, vector<dbl>(k, 0));
        for (ll i = 0;i < k; i++) res[i][i] = 1;

        while (n > 0) {
            if (n & 1) {
                res = mul(tr, res);
            }
            n >>= 1;
            tr = mul(tr, tr);
        }

        return res;
    }

    // returns nth term of the sequence
    double getNthTerm(ll n) {
        cout << n << endl;
        if (n < k) {
            return base[k - n - 1][0];
        }

        vector<vector<dbl>> res = binpow(tr, n - k + 1);

        res = mul(res, base);

        return res[0][0];
    }
};


void HHM() {
    ll  n, i, j, k;
    cin >> n;  double p; cin >> p;

    matrixExpo m(2);
    m.base = { {((p * p) + ((1 - p) * (1 - p)))}, {1 - p} };
    m.tr = { {(1 - p), ((p * p) + ((1 - p) * (1 - p)))},{(1.0), (0.0)} };

    cout << fixed << setprecision(10) << m.getNthTerm(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
