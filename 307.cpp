#include<bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) tree[node] = nums[l];
        else {
            int mid = (l + r) / 2;
            build(nums, node * 2, l, mid);
            build(nums, node * 2 + 1, mid + 1, r);
            tree[node] = tree[node* 2] + tree[node * 2 + 1];
        } 
    }

    void updateTree(int node, int l, int r, int i, int val) {
        if (l == r) tree[node] = val;
        else {
            int mid = (l + r) / 2;
            if (i <= mid) updateTree(node * 2, l, mid, i, val);
            else updateTree(node * 2 + 1, mid + 1, r, i, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        // nếu l và r thuộc ql, qr thì trả luôn tổng từ l đến r
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }

public: 
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }
    
    void update(int index, int val) {
        updateTree(1, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};
