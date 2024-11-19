#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = (dp[i >> 1]) + (i & 1);
        }

        return dp;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<int> res = sol.countBits(n);
    for (auto x : res) {
        cout << x << " ";
    }
}