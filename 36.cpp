#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Mảng bool để theo dõi sự xuất hiện của số từ 1 đến 9 ở hàng, cột và ô
        bool rows[9][9] = {false};  // rows[i][val] = true nếu giá trị 'val' xuất hiện trong hàng i
        bool cols[9][9] = {false};  // cols[j][val] = true nếu giá trị 'val' xuất hiện trong cột j
        bool boxes[9][9] = {false}; // boxes[k][val] = true nếu giá trị 'val' xuất hiện trong ô k

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;  
                }

                char value = board[r][c];
                int val = value - '1';  // Chuyển ký tự thành số từ 0 đến 8 để vào chỉ số
                int boxIndex = (r / 3) * 3 + (c / 3);  // Tính chỉ số của ô 3x3, tính từ 0 đến 8, đếm từ trái sang phải, trên xuống dưới

                if (rows[r][val] || cols[c][val] || boxes[boxIndex][val]) {
                    return false;  // Nếu số đã xuất hiện trong hàng, cột hoặc ô, trả về false
                }

                rows[r][val] = true;
                cols[c][val] = true;
                boxes[boxIndex][val] = true;
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
    cout << sol.isValidSudoku(board);
}