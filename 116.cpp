#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int val) : val(val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) 
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* rightNode = nullptr;
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();
                cur->next = rightNode;
                rightNode = cur;
                if (cur->right) {
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }
        return root;
    }
};