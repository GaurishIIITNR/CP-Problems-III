#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const ll mod = 1e9 + 7;

class matrixExpo {
    public:
    ll k; // dependent on previous k terms
    vector<vector<ll>> base, tr; // base case matrix and transformation matrix

    matrixExpo(ll k) {
        this->k = k;
        tr.assign(k, vector<ll>(k, 0)); // K X k matrix
        base.assign(k, vector<ll>(1, 0)); // 1 X k matrix
    }

    // matrix multiplication
    vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        vector<vector<ll>>res(a.size(), vector<ll>(b[0].size(), 0));

        for (int i = 0; i < a.size(); i++) {
            for (int k = 0; k < b[0].size(); k++) {
                for (int j = 0; j < a[0].size(); j++) {
                    res[i][k] += a[i][j] * b[j][k]; res[i][k] %= mod;
                }
            }
        }

        return res;
    }

    // binary exponentiation
    vector<vector<ll>> binpow(vector<vector<ll>>& tr, ll n) {

        vector<vector<ll>>res(k, vector<ll>(k, 0));
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
    ll getNthTerm(ll n) {
        if (n < k) return base[k - n - 1][0];

        vector<vector<ll>> res = binpow(tr, n - k + 1);

        res = mul(res, base);

        return res[0][0];
    }
};

int main() {
    ll n; cin >> n;

    matrixExpo m(2);
    m.base = { {1}, {0} };
    m.tr = { {1, 1}, {1, 0} };

    cout << m.getNthTerm(n) << endl;

}
