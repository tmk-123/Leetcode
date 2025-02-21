#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        if (prices[0] + prices[1] > money) return money;
        return money - prices[0] - prices[1]; 
    }
};  

int main() {
    vector<int> a = {1, 2, 3};
    Solution sol;
    cout << sol.buyChoco(a, 3);
}