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

#define vin(v) for(auto &z: v)cin >> z
#define deb(v) cout << #v << " = " << v <<  endl
#define vout(v) for(auto z:v)cout << z << " " ; cout<<endl
#define deb2(v, k) cout << #v << " = " << v << " "<< #k << " = " << k << endl;
#define pout(mp) for(auto z: mp)cout << z.F << " " << z.S << endl

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update>sat;
typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update>multisat;


struct node {
    node* ch[2];
    bool end = false;
    node() {
        ch[0] = ch[1] = NULL;
    }
};

map<ll, bool> mp;

void primes(ll n) {
    vector<bool>v(n + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            mp[i] = true;
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }
    return;
}

struct tri {
    node* r;
    tri() {
        r = new node();
    }

    void ins(bitset<20>& s) {
        node* t = r;
        for (ll i = 19; i >= 0; i--) {
            ll x = s[i];
            if (t->ch[x] == NULL) {
                t->ch[x] = new node();
            }
            t = t->ch[x];
        }
        t->end = true;
    }

    // void f(bitset<29>&s, ll i, node *t, ll &ans) {
    //     if (i == 20) {
    //         ans = 0;
    //         return;
    //     }
    //     ll x = s[i];
    //     if (t->ch[x ^ 1] != NULL) {
    //         ans |= (1 << (19 - i));
    //         f(s, i + 1, t->ch[x ^ 1], ans);
    //     }
    //     else {
    //         f(s, i + 1, t->ch[x], ans);
    //     }
    // }


};



void HHM() {
    ll  n, i, j, k;
    cin >> n;


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    primes(500000 + 2);
    while (t--) { HHM(); }
}
