// ------------------------------------------------Basic Daily Used----------------------------------------------------//

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
    while(t--){ HHM(); }
}


// ------------------------------------------------String Tokenizer----------------------------------------------------//


/*
    Remember** that if you already used cin then use cin.ignore() to reach in next line.
*/

vector<ll> tokenizer(string s) {
    vector<ll>v;
    char* t = strtok((char*)s.c_str(), " ");

    while (t != NULL) {
        ll x = stoll(t);
        v.pb(x);
        t = strtok(NULL, " ");
    }

    return v;
}


// --------------------------------------------LCA, KthPar, BLift(Sparsh Table)----------------------------------------------------//



vector<vector<ll>>adj, par;
vector<ll>lev;

void reset(ll n) {
    adj.assign(n + 1, {});
    par.assign(n + 1, vector<ll>(20, 0));
    lev.assign(n + 1, 0);
}

void BLift(ll src, ll p) {
    par[src][0] = p;
    lev[src] = lev[p] + 1;

    for (ll i = 1;i < par[0].size(); i++) {
        par[src][i] = par[par[src][i - 1]][i - 1];
    }

    for (auto x : adj[src]) {
        if (x != p)  BLift(x, src);
    }  return;
}

ll KthPar(ll node, ll k) {
    ll i = 0; while (k) {
        if (k & 1) node = par[node][i];
        k >>= 1; i++;
    } return node;
}

ll lca(ll u, ll v) {

    if (lev[u] > lev[v]) u = KthPar(u, lev[u] - lev[v]);
    else if (lev[v] > lev[u]) v = KthPar(v, lev[v] - lev[u]);
    if (u == v) return u;

    for (ll i = par[0].size() - 1;i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i]; v = par[v][i];
        }
    }

    return par[u][0];
}


// -----------------------------------------------------DSU----------------------------------------------------//


class DSU {
    public:
    vector<ll>par, sz, rank;
    ll n;

    DSU(ll n) {
        this->n = n;
        par.assign(n + 1, -1);
        sz.assign(n + 1, 1);
        rank.assign(n + 1, 0);
    }

    ll findPar(ll node) {
        if (par[node] == -1) return node;
        // used path compression
        return par[node] = findPar(par[node]);
    }

    void UnionByRank(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;
        if (rank[pu] == rank[pv]) {
            rank[pu]++; par[pv] = pu;
        }
        else if (rank[pu] > rank[pv])par[pv] = pu;
        else par[pu] = pv;    return;
    }

    void UnionBysz(ll u, ll v) {
        ll pu = findPar(u);
        ll pv = findPar(v);
        if (pu == pv) return;
        if (sz[pu] >= sz[pv])sz[pu] += sz[pv], par[pv] = pu;
        else sz[pv] += sz[pu], par[pu] = pv;
        return;
    }

    bool get(ll u, ll v) {
        return findPar(u) == findPar(v);
    }

    // ll gett(ll node) {
    //     if (node == -1) return 0;
    //     ll ans = size[node];
    //     ans += get(par[node]);
    //     return ans;
    // }
};


// --------------------------------------------------------Primes & Factorization----------------------------------------------------//


vector<ll>pr;
void primes(ll n) {
    vector<bool>v(n + 1, true);
    v[0] = v[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (v[i]) {
            pr.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }
    return;
}

void factors(ll n) {
    // call this function in main for minimizing time complexity
    // primes(sqrt(n) + 2);
    for (auto x : pr) {
        if (x * x > n)break;
        while (n % x == 0) {
            cout << x << " "; //can be insert or push_back
            n /= x;
        }
    }
    if (n > 1)cout << n << " ";// can be insert or push_back
    return;
}


// --------------------------------------------------------Mo's Algorithms----------------------------------------------------//


class query {
    public:
    ll l, r, block, i, val;

    query(ll l, ll r, ll n, ll i, ll val) {
        this->l = l;
        this->r = r;
        block = l / (ll)sqrtl(n + 1);
        this->i = i;
        this->val = val;
    }

    bool operator < (const query& q) const {
        if (block != q.block) return block < q.block;
        return r < q.r;
    }
};

class Mo {
    public:
    umap<ll, ll> val;
    umap<ll, bool> mp;
    ll l = 0, r = -1;

    void add(ll node) {
        if (mp[node] == 1) mp[node] = 0, val[v[node]]--;
        else mp[node] = 1, val[v[node]]++;
        return;
    }

    void remove(ll node) {
        if (mp[node] == 0) mp[node] = 1, val[v[node]]++;
        else mp[node] = 0, val[v[node]]--;
        return;
    }

    ll getAns(ll i, ll j, ll k) {
        while (r < j) {
            r++;
            add(path[r]);
        }
        while (r > j) {
            remove(path[r]);
            r--;
        }
        while (l < i) {
            remove(path[l]);
            l++;
        }
        while (l > i) {
            l--;
            add(path[l]);
        }
        return val[k];
    }
};


// --------------------------------------------------------Segment Trees----------------------------------------------------//


class SegTree {
    public:
    ll n; vector<ll> tr, lazy;

    // Constructor
    SegTree(ll size) {
        n = size;
        tr.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }

    // update a node with left and right child
    void updateNode(ll i) {
        tr[i] = max(tr[2 * i], tr[2 * i + 1]); return;
    }

    //Build a tree
    void build(vector<ll>& a, ll i, ll s, ll e) {
        if (s == e) {
            tr[i] = a[s]; return;
        }
        ll mid = (s + e) / 2;
        build(a, 2 * i, s, mid);
        build(a, 2 * i + 1, mid + 1, e);
        updateNode(i);  return;
    }

    // Update a node
    void update(ll i, ll s, ll e, ll pos, ll val) {
        if (e < pos || s > pos) return;

        if (s == e && s == pos) {
            tr[i] = val; return;
        }

        ll mid = (s + e) / 2;
        update(2 * i, s, mid, pos, val);
        update(2 * i + 1, mid + 1, e, pos, val);
        updateNode(i); return;
    }

    // Query for without lazy propagation
    ll query(ll i, ll s, ll e, ll l, ll r) {
        if (s > e) return 0;
        if (l <= s && r >= e) return tr[i];
        ll mid = (s + e) / 2;
        ll left = query(2 * i, s, mid, l, r);
        ll right = query(2 * i + 1, mid + 1, e, l, r);
        return max(left, right);
    }

    //Resolve the lazy propagation of a node
    // Flag for checking if the node is leaf or not
    void resolveLazy(ll i, bool flag) {
        tr[i] = lazy[i];
        if (flag) {
            lazy[2 * i] = lazy[i];
            lazy[2 * i + 1] = lazy[i];
        }  lazy[i] = 0; return;
    }

    //Range update with lazy propagation
    void rangeUpdate(ll i, ll s, ll e, ll l, ll r, ll val) {
        if (lazy[i]) {
            resolveLazy(i, (s != e));
        }
        if (s > e || l > e || r < s) return;
        if (l <= s && e <= r) {
            lazy[i] = val;
            resolveLazy(i, (s != e));
            return;
        }
        ll mid = (s + e) / 2;
        rangeUpdate(2 * i, s, mid, l, r, val);
        rangeUpdate(2 * i + 1, mid + 1, e, l, r, val);
        updateNode(i);
    }

    //Range query with lazy propagation
    ll rangeQuery(ll i, ll s, ll e, ll l, ll r) {
        if (lazy[i]) {
            resolveLazy(i, (s != e));
        }
        if (s > e || l > e || r < s) return 0;
        if (l <= s && e <= r) {
            return tr[i];
        }
        ll mid = (s + e) / 2;
        ll left = rangeQuery(2 * i, s, mid, l, r);
        ll right = rangeQuery(2 * i + 1, mid + 1, e, l, r);
        return max(left, right);
    }
};



// --------------------------------------------------------Matrix Exponentiation----------------------------------------------------//


class matrixExpo {
    public:
    ll k; // dependent on previous k terms
    vector<vector<ll>> base, tr; // base case matrix and transformation matrix

    matrixExpo(ll k) {
        this->k = k;
        tr.assign(k, vector<ll>(k, 0)); // k X k matrix
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

//--------------------------------------------------------------Trie-----------------------------------------------------

struct node {
    node* ch[2];
    node() {
        ch[0] = ch[1] = NULL;
    }
};

struct trie {
    node* root;

    trie() {
        root = new node();
    }

    void insert(int x) {
        node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (!curr->ch[b]) {
                curr->ch[b] = new node();
            }
            curr = curr->ch[b];
        }
    }

    int qr(int x) {
        node* curr = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int b = (x >> i) & 1;

            if (curr->ch[b ^ 1]) {
                ans |= (1 << i); curr = curr->ch[b ^ 1];
            }
            else {
                curr = curr->ch[b];
            }
        }

        return ans;
    }
};

// -------------------------------------------------------Basic Python----------------------------------------------------//


// # हर हर महादेव
// import math


// t = int(input())
// while t > 0 :

//     n = int(input())
//     v = list(map(int, input().split()))
   

//     t -= 1