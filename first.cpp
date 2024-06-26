// #include <iostream>
// #include <vector>
// #include <string>
// #include <unordered_map>

// class Solution {
//     public:
//     bool check(const std::string& a, const std::string& b) {
//         if (a.size() != b.size()) return false;
//         int cnt = 0;
//         for (int i = 0; i < a.length(); i++) {
//             if (a[i] != b[i]) cnt++;
//             if (cnt > 1) return false;
//         }
//         return cnt == 1;
//     }

//     std::vector<int> path;
//     std::unordered_map<int, int> dp;

//     int f(const std::vector<std::string>& w, const std::vector<int>& g, int i, int pr) {
//         if (i == g.size()) return 0;
//         if (dp.find(i) != dp.end()) return dp[i];

//         int pick = 0, notpick = 0;

//         if ((pr == -1) || (g[pr] != g[i] && check(w[pr], w[i]))) {
//             pick = 1 + f(w, g, i + 1, i);
//         }

//         notpick = f(w, g, i + 1, pr);

//         if (pick >= notpick) {
//             path.push_back(i);
//         }

//         dp[i] = std::max(pick, notpick);
//         return dp[i];
//     }

//     std::vector<std::string> getWordsInLongestSubsequence(int n, std::vector<std::string>& w, std::vector<int>& g) {
//         path.clear();
//         dp.clear();
//         f(w, g, 0, -1);

//         std::vector<std::string> ans;
//         for (int i = path.size() - 1; i >= 0; i--) {
//             ans.push_back(w[path[i]]);
//         }

//         return ans;
//     }
// };

// int main() {
//     Solution solution;
//     int n = 3;
//     std::vector<std::string> w = { "bdb", "aaa", "ada" };
//     std::vector<int> g = { 2, 1, 3 };
//     std::vector<std::string> longestSubsequence = solution.getWordsInLongestSubsequence(n, w, g);

//     std::cout << "Selected strings in the longest subsequence: ";
//     for (const std::string& word : longestSubsequence) {
//         std::cout << word << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#include "gen.h"
using namespace gen;

int x() {
    return 0;
}

int y() {
    return 1;
}

int main() {

}
