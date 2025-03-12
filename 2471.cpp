#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                v.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            for (int i = 0; i < size; i++) {
                int key = i;
                for (int j = i + 1; j < size; j++) {
                    if (v[key] > v[j]) key = j;
                }
                if (i != key) {
                    swap(v[i], v[key]);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};