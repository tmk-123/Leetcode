#include<bits/stdc++.h>

using namespace std;

/*
    có dãy 1 2 3 0 1
                    0
               buy/   \cooldown
               -1       0
           sell/ \cd  buy/ \cd
              1   -1   -2   0
     cooldown/     /\   /\  /\
         buy/\cd   
    rút gọn các nhánh bằng quy hoạch động, sử dụng max
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> hold(n, 0), sold(n, 0), rest(n, 0);
        hold[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;

        for (int i = 1; i < n; i++) {
            // giữ tiếp từ hôm qua hoặc mua cổ phiếu hôm nay(dựa vào rest hôm trước)
            hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);

            sold[i] = hold[i - 1] + prices[i];

            // nghỉ ngơi từ ngày hôm trước hoặc bán từ hôm trước
            rest[i] = max(rest[i - 1], sold[i - 1]);
        }

        return max(rest[n - 1], sold[n - 1]);
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