#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = q.front();
            q.pop();
            if (prev->left) q.push(prev->left);
            if (prev->right) q.push(prev->right);

            for (int i = 1; i < size - 1; i++) {
                Node* current = q.front();
                q.pop();

                prev->next = current;
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
                prev = current;
            }

            if (size > 1) {
                Node* current = q.front();
                prev->next = current;
                q.pop();
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
                current->next = nullptr;
            }
            else prev->next = nullptr;
        }

        return root;
    }
};
