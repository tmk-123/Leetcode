#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(rowIndex + 1);

        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    res[i].push_back(1);
                }
                else {
                    res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
                }
            }
        }

        return res[rowIndex];
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<int> res = sol.getRow(n);
}