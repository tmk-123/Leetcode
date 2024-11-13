#include<bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] > prices[i - 1]) {
//                 profit += prices[i] - prices[i - 1];
//             }
//         }
//         return profit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0, profit = 0;
        while (i < n) {
            int start = i;
            while (start < n - 1) {
                if (prices[start] > prices[start + 1]) {
                    start++;
                }
                else break;
            }
            int end = start;
            while (end < n - 1) {
                if (prices[end] < prices[end + 1]) {
                    end++;
                }
                else break;
            }

            profit += prices[end] - prices[start];
            i = end + 1;
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