#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++) dp[i] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // sử dụng trực tiếp j hoặc dùng dp[j] vì trong trường hợp nhỏ thì j > dp[j]  
                dp[i] = max(dp[i], max(j, dp[j])  * (i - j));
            }
        }
    
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.integerBreak(n);
}