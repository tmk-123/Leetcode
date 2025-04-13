#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, 1, 1, -1, 0, 0, 1};
int dy[] = {-1, 1, -1, 1, 0, -1, 1, 0};

class NeighborSum {
private:
    vector<vector<int>> v; 
    unordered_map<int, pair<int, int>> m;
    int n;
public:    
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[grid[i][j]] = {i, j};
            }
        }
        v = grid;
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        for (int i = 4; i < 8; i++) {
            int nx = m[value].first + dx[i];
            int ny = m[value].second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) sum += v[nx][ny];
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int nx = m[value].first + dx[i];
            int ny = m[value].second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) sum += v[nx][ny];
        }
        return sum;
    }
};