#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*> st;
        int i = 0;
        while (i < s.size()) {
            int depth = 0;
            while (i < s.size() && s[i] == '-') {
                i++;
                depth++;
            }

            int val = 0;
            while (i < s.size() && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }

            TreeNode* newNode = new TreeNode(val);
            
            // pop đến khi cùng depth
            while (st.size() > depth) st.pop();

            if (!st.empty()) {
                if (st.top()->left == nullptr) st.top()->left = newNode;
                else st.top()->right = newNode;
            }

            st.push(newNode);
        }

        while (st.size() > 1) st.pop();
        return st.top();
    }
};