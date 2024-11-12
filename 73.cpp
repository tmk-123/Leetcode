#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (rows[i]) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            if (cols[j]) {
                for (int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    Solution sol;
    sol.setZeroes(v);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        } 
        cout << endl;
    }
}