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
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }

        int maxDep = 0;
        for (Node* child : root->children) {
            maxDep = max(maxDep, maxDepth(child));
        }

        return maxDep + 1;
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
    cout << sol.maxDepth(root1);
}