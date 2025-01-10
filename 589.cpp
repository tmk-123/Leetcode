#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(Node* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        for (Node* child : root->children) {
            dfs(child, res);
        }
    }
};

int main() {
    Node* root1 = new Node(1);
    Node* child1 = new Node(3);
    Node* child2 = new Node(2);
    Node* child3 = new Node(4);
    Node* grandChild1 = new Node(5);
    Node* grandChild2 = new Node(6);

    root1->children = {child1, child2, child3};
    child1->children = {grandChild1, grandChild2};

    Solution sol;
    vector<int> res = sol.preorder(root1);
    for (int x : res) {
        cout << x << " ";
    }
}