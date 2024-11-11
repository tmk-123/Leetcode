#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int c1 = 0, h1 = 0, h2 = n - 1, c2 = m - 1;

        while (c1 <= c2 && h1 <= h2) {
            for (int i = c1; i <= c2; i++) {
                res.push_back(matrix[h1][i]);
            }
            h1++;

            for (int i = h1; i <= h2; i++) {
                res.push_back(matrix[i][c2]);
            }
            c2--;

            if (h1 <= h2) {
                for (int i = c2; i >= c1; i--) {
                    res.push_back(matrix[h2][i]);
                }
            }
            h2--;

            if (c1 <= c2) {
                for (int i = h2; i >= h1; i--) {
                    res.push_back(matrix[i][c1]);
                }
            }
            c1++;
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    vector<int> res = sol.spiralOrder(matrix);
    
    for (int i = 0; i < n * n; i++) {
        cout << res[i] << " ";
    }
}