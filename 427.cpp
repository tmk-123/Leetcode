#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    bool isSame(vector<vector<int>>& grid, int x, int y, int size) {
        int value = grid[x][y];
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                if (grid[i][j] != value) return false;
            }
        }

        return true;
    }
    
    Node* dfs(vector<vector<int>>& grid, int x, int y, int size) {
        if (isSame(grid, x, y, size)) return new Node(grid[x][y], true);

        int newSize = size / 2;
        Node* topLeft = dfs(grid, x, y, newSize);
        Node* topRight = dfs(grid, x, y + newSize, newSize);
        Node* bottomLeft = dfs(grid, x + newSize, y, newSize);
        Node* bottomRight = dfs(grid, x + newSize, y + newSize, newSize);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, 0, 0, grid.size());
    }
}; 