#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int i = 0;
        int minCost = 0;
        while (i < cost.size() - 1) {
            minCost += cost[i] + cost[i + 1];
            i += 3;
        }
        if (i < cost.size()) minCost += cost[cost.size() - 1];
        
        return minCost;
    }
};

int main() {
    vector<int> v = {6,5,7,9,2,2};
    Solution sol;
    cout << sol.minimumCost(v);
}