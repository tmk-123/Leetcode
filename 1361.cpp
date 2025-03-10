#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);

        // kiểm tra mỗi nút chỉ có một cha
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (parent[leftChild[i]] != -1) return false;
                parent[leftChild[i]] = i;
            }
            if (rightChild[i] != -1) {
                if (parent[rightChild[i]] != -1) return false;
                parent[rightChild[i]] = i;
            }
        }

        // kiểm tra có 1 gốc duy nhất không
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                if (root != -1) return false;
                root = i;   
            }
        }

        if (root == -1) return false;

        // Kiểm tra tính liên thông
        queue<int> q;
        q.push(root);
        vector<bool> visited(n, false);
        visited[root] = true;
        int count = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            if (leftChild[node] != -1) {
                if (visited[leftChild[node]]) return false; // xuất hiện chu trinh
                visited[leftChild[node]] = true;
                q.push(leftChild[node]);
            }

            if (rightChild[node] != -1) {
                if (visited[rightChild[node]]) return false;
                visited[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }
        
        return count == n;
    }
};