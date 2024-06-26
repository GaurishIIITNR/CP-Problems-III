#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll mod = 1e9 + 7;

struct node {
    node* ch[26];
    bool end = false;
    node() {
        for (ll i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
    }
};

struct trie {
    node* t;
    trie() {
        t = new node();
    }

    void insert(string& s) {
        node* curr = t;
        for (auto x : s) {
            if (curr->ch[x - 'a'] == nullptr) {
                curr->ch[x - 'a'] = new node();
            }
            curr = curr->ch[x - 'a'];
        }
        curr->end = true;
    }

    vector<ll> dp;

    ll f(string& s, ll i) {
        node* curr = t;
        ll ans = 0;
        if (dp[i] != -1) return dp[i];

        int j = i;
        for (j = i; j < s.size(); j++) {
            char x = s[j];

            if (curr->ch[x - 'a'] == nullptr) {
                break;
            }

            if (curr->ch[x - 'a']->end) {
                ans += f(s, j + 1); ans %= mod;
            }

            curr = curr->ch[x - 'a'];
        }

        if (j == s.size() && curr->end) ans++; ans %= mod;
        return dp[i] = ans;
    }

    ll qr(string& s) {
        dp.assign(s.size() + 2, -1);
        return f(s, 0);
    }
};

int main() {
    string s;cin >> s;
    ll k; cin >> k;

    trie t;
    for (ll i = 0; i < k; i++) {
        string ss; cin >> ss;t.insert(ss);
    }

    cout << t.qr(s);
}
