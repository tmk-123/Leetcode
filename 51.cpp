#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        // diagonal1: đường chéo phụ, diag2 đường chéo chính(đi từ trên trái xuống dưới phải)
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        vector<vector<string>> res;
        solve(0, board, n, cols, diag1, diag2, res);

        return res;
    }

    void solve(int row, vector<string>& board, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // tổng i và j trong đường chéo phụ bằng nhau còn hiệu trong đường chéo chính bằng nhau
            if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
                board[row][col] = 'Q';
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

                solve(row + 1, board, n, cols, diag1, diag2, res);

                board[row][col] = '.';
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
            }
        }
        return;
    }
};


int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(n);
    for (auto x : res) {
        for (auto y : x) {
            cout << y << endl;
        }
        cout << endl;
    }
}