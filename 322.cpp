#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 100000);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j : coins) {
                if (i >= j) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }  
            }
        }
        if (dp[amount] == 100000) return -1;
        return dp[amount];
    }
};

int main() {
    int amount;
    cin >> amount;
    int n;
    vector<int> coins;
    while (cin >> n) {
        coins.push_back(n);
    }

    Solution sol;
    cout << sol.coinChange(coins, amount);
}