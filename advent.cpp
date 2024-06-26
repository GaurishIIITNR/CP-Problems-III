#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector<string>v = { "one", "two","three", "four", "five", "six", "seven", "eight","nine" };

int locc(const std::string& a, const std::string& b) {
    size_t found = a.rfind(b);  // Using rfind to find the last occurrence

    if (found != std::string::npos) {
        return static_cast<int>(found);
    }
    else {
        // Return -1 if the substring is not found
        return -1;
    }
}

int main() {
    string s;
    long long int ans = 0;

    while (cin >> s) {
        int a, pa = s.size(), b, pb = -1;
        int i = 0;

        for (int j = 0; j < v.size(); j++) {
            auto r = s.find(v[j]);
            if (r != string::npos) {
                if (pa > r) {
                    pa = r;
                    a = j + 1;
                }
            }
        }

        while (i < pa) {
            if (s[i] >= '0' && s[i] <= '9') {
                a = s[i] - '0';
                break;
            }
            i++;
        }

        for (int j = 0; j < v.size(); j++) {
            auto r = locc(s, v[j]);
            if (pb < r) {
                pb = r;
                b = j + 1;
            }
        }

        i = s.size() - 1;
        while (i > pb) {
            if (s[i] >= '0' && s[i] <= '9') {
                b = s[i] - '0';
                break;
            }
            i--;
        }

        // cout << a << "" << b << endl;
        a *= 10; a += b;
        ans += a;
    }
    cout << ans;
}
