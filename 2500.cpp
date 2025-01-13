#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res = 0;

        for (auto& row : grid) {
            sort(row.rbegin(), row.rend());
        }

        for (int col = 0; col < grid[0].size(); col++) {
            int maxValue = 0;
            for (int row = 0; row < grid.size(); row++) {
                maxValue = max(maxValue, grid[row][col]);
            }
            res += maxValue;
        }

        return res;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2, 4},
        {3, 3, 1}
    };
    
    Solution sol;
    cout << sol.deleteGreatestValue(grid);
}