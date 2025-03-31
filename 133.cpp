#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // đồ thị 2 chiều nên dùng visited
    unordered_map<Node*, Node*> visited;

    Node* clone(Node* node) {
        if (!node) return NULL;
        if (visited.count(node)) return visited[node];

        Node* newNode = new Node(node->val);
        visited[node] = newNode;

        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(clone(neighbor));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};