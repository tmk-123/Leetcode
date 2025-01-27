#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); 
            vector<int> level;

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                level.push_back(current->val);

                for (Node* child : current->children) {
                    q.push(child);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};
