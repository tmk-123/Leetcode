#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> v;
        v.push_back(root->val);

        while (!q.empty()) {
            long long sum = 0;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            v.push_back(sum);
        }

        if (v.size() < k) return -1;
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < v.size(); i++) {
            k--;
            if (k == 0) return v[i];
        }
        return -1;
    }
}; 