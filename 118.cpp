#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> res(numRows);

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    res[i].push_back(1);
                }
                else {
                    res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
                }
            }
        }

    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<vector<int>> res = sol.generate(n);
}