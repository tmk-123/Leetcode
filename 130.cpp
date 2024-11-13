#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        // Duyệt qua các ô ở biên
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') DFS(board, n, m, i, 0);
            if (board[i][m - 1] == 'O') DFS(board, n, m, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') DFS(board, n, m, 0, j);
            if (board[n - 1][j] == 'O') DFS(board, n, m, n - 1, j);
        }

        // Thay đổi các ô 'O' bị bao quanh thành 'X' và khôi phục các ô 'T' về 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

    void DFS(vector<vector<char>>& board, int n, int m, int x, int y) {
        board[x][y] = 'T'; // Đánh dấu ô đã thăm tạm thời là 'T'
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newY >= 0 && newX < n && newY < m && board[newX][newY] == 'O') {
                DFS(board, n, m, newX, newY);
            }
        }
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    Solution sol;
    sol.solve(board);
}