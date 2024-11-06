#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    visited[i][j] = true;
                    if (DFS(board, word, i, j, 1, visited, n, m)) return true;
                }
            }
        }
        return false;
    }

    int DFS(vector<vector<char>>& board, string word, int x, int y, int cnt, vector<vector<bool>> &visited, int n, int m) {
        if (cnt == word.length()) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && word[cnt] == board[newX][newY] && !visited[newX][newY]) {
                visited[newX][newY] = true;

                if(DFS(board, word, newX, newY, cnt + 1, visited, n, m)) return 1;
                visited[newX][newY] = false;
            }
        }
        return 0;
    }
};

int main() {
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    string word;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    cin >> word;

    Solution sol;
    cout << sol.exist(board, word);
}