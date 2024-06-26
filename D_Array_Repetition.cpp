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

struct node {
    node* next;
    vector<ll>v;
    ll val, freq;
    node(node* next) {
        this->next = next;
        val = 0;
    }
};

void HHM() {

    ll  n, i, j, k;
    cin >> n >> k;
    vector<ll>a;

    node* rnext = NULL;

    while (n--) {
        ll x, y; cin >> x >> y;
        if (x == 1) {
            a.pb(y);
        }
        else {
            node* root = new node(rnext);

            root->v = a;
            root->freq = y + 1;
            root->val = a.size();

            if (root->next != NULL) {
                root->val += root->next->val;
            }

            root->val *= (root->freq);
            rnext = root;
            a.clear();
        }
    }

    node* finale = rnext;
    while (k--) {
        ll idx; cin >> idx; idx--;

        node* tmp = finale;
        while (tmp != NULL) {
            idx %= (tmp->val / tmp->freq);

            if (tmp->next == NULL) {
                cout << tmp->v[idx] << " "; break;
                break;
            }
            else {
                ll left = tmp->next->val;
                ll right = tmp->v.size();

                if (idx < left) {
                    tmp = tmp->next;
                }
                else {
                    idx -= left;
                    cout << tmp->v[idx] << " ";
                    break;
                }
            }

        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    cin >> t;
    while (t--) { HHM(); }
}
