#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> q;  // Hàng đợi lưu các nút chưa đủ 2 con

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> temp;
        temp.push(root);
        
        // Tìm các nút chưa đủ 2 con để đưa vào hàng đợi
        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();
            
            if (!node->left || !node->right) {
                q.push(node);
            }
            
            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
    }

    int insert(int v) {
        TreeNode* parent = q.front(); // Lấy nút cha đầu tiên
        TreeNode* newNode = new TreeNode(v);

        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            q.pop(); // Nếu đã đủ 2 con thì loại bỏ khỏi hàng đợi
        }
        
        q.push(newNode); // Thêm nút mới vào hàng đợi
        
        return parent->val;
    }

    TreeNode* get_root() {
        return root;
    }
};