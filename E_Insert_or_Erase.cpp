// Warning: Coding is an addiction.

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

struct dll {
    dll* l, * r;
    ll val;

    dll(ll vall) {
        l = r = NULL;
        val = vall;
    }
};

dll* head = new dll(-1), * tail = new dll(-1);

dll* add(dll* node, ll val) {
    dll* next = node->r;
    dll* new_node = new dll(val);
    node->r = new_node;
    new_node->l = node;
    new_node->r = next;
    next->l = new_node;
    return new_node;
}

void del(dll* node) {
    dll* prev = node->l;
    dll* next = node->r;
    prev->r = next;
    next->l = prev;
    delete node;
}

void HHM() {
    ll  n, i, j, k;
    cin >> n;

    vector<ll> v(n); vin(v);

    map<ll, dll*> mp;

    head->r = tail;
    tail->l = head;

    mp[v[0]] = add(head, v[0]);

    for (i = 1; i < n;i++) {
        mp[v[i]] = add(mp[v[i - 1]], v[i]);
    }

    ll q; cin >> q;
    while (q--) {
        ll t; cin >> t;
        if (t == 2) {
            ll x; cin >> x;
            del(mp[x]);
        }
        else {
            ll x, y; cin >> x >> y;
            mp[y] = add(mp[x], y);
        }
    }

    dll* cur = head->r;
    while (cur != tail) {
        cout << cur->val << " ";
        cur = cur->r;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) { HHM(); }
}
