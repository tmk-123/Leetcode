#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // max1 là chiều cao của nhánh cao nhất, max2 là chiều cao nhánh còn lại
    unordered_map<int, int> height, max1, max2, levelArr;

    int computeHeight(TreeNode* root, int level) {
        if (!root) return 0;
        levelArr[root->val] = level;
        height[root->val] = 1 + max(computeHeight(root->left, level + 1), computeHeight(root->right, level + 1));

        if (max1[level] < height[root->val]) {
            max2[level] = max1[level];
            max1[level] = height[root->val];
        }
        else if (max2[level] < height[root->val]) max2[level] = height[root->val];

        return height[root->val];   
    } 

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> res;
        computeHeight(root, 0);

        for (int& q : queries) {
            // nếu max1 là nốt cao nhất thì push nốt 2
            int level = levelArr[q];
            if (max1[level] == height[q]) res.push_back(max2[level] + level - 1);
            else res.push_back(max1[level] + level - 1);
        }    
        return res;
    }
};