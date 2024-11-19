#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[i][j])) {
                    // thử từng số vào ô 
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (solve(board)) return true;
                            board[i][j] = '.'; // nếu không đúng thì quay lui 
                        }
                    }
                    // Sau khi đã thử tất cả các số từ 1-9 mà không tìm
                    // được lời giải hợp lệ thì cần quay lui về phương án khác
                    return false;
                }
            }
        } 
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            // xét trong hàng, cột, ô
            if (board[row][i] == num || board[i][col] == num ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution sol;
    sol.solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}