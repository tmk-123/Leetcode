#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buyPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }    

            profit = max(profit, prices[i] - buyPrice);
        }

        return profit;
    }
};

int main() {
    int n;
    vector<int> prices;
    while (cin >> n) {
        prices.push_back(n);
    }

    Solution sol;
    cout << sol.maxProfit(prices);
}