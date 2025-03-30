#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        
        // dùng temp để kiểm soát số lần cập nhập, tránh cái nhanh cái chậm
        for (int i = 0; i <= k; i++) {
            vector<int> temp = cost;  // Dùng để tránh cập nhật ngay trong lần lặp
            for (auto& flight : flights) {
                int u = flight[0], v = flight[1], price = flight[2];
                if (cost[u] != INT_MAX && cost[u] + price < temp[v]) {
                    temp[v] = cost[u] + price;
                }
            }
            cost = temp;  // Cập nhật chi phí sau mỗi lần duyệt
        }
        
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};

