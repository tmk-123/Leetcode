#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int cnt = 0;

        // diagonal1: đường chéo phụ, diag2 đường chéo chính(đi từ trên trái xuống dưới phải)
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

        solve(0, board, n, cols, diag1, diag2, cnt);

        return cnt;
    }

    void solve(int row, vector<string>& board, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int &cnt) {
        if (row == n) {
            cnt++;
            return;
        }

        for (int col = 0; col < n; col++) {
            // tổng i và j trong đường chéo phụ bằng nhau còn hiệu trong đường chéo chính bằng nhau
            if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
                board[row][col] = 'Q';
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

                solve(row + 1, board, n, cols, diag1, diag2, cnt);

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
    cout << sol.totalNQueens(n);
}