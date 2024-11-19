#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            // i >> 1 là dịch bit sang phải 1 đơn vị, tức là vứt số 1 cuối cùng đi
            // i & 1 là số cuối của i là 0 hay 1
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