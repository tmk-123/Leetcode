#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> tree;
    int n;
    
    void build(vector<int>& v, int node, int l, int r) {
        if (l == r) tree[node] = v[l];
        else {
            int mid = (l + r) / 2;
            build(v, node * 2, l, mid);
            build(v, node * 2 + 1, mid + 1, r);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int l, int r, int id) {
        if (l == r) tree[node] = -1;
        else {
            int mid = (l + r) / 2;
            if (id <= mid) update(node * 2, l, mid, id);
            else update(node * 2 + 1, mid + 1, r, id);
            tree[node] = max(tree[node * 2], tree[2 * node + 1]);
        }
    }
    
    int query(int node, int l, int r, int fruit) {
        if (tree[node] < fruit) return -1;
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[2 * node] >= fruit) return query(2 * node, l, mid, fruit);
        else return query(node * 2 + 1, mid + 1, r, fruit);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        tree.resize(4 * n);
        build(baskets, 1, 0, n - 1);

        int unplaced = 0;
        for (int fruit : fruits) {
            int idx = query(1, 0, n - 1, fruit);
            if (idx == -1) unplaced++;
            else update(1, 0, n - 1, idx);
        }

        return unplaced;
    }
};