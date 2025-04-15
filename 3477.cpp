#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> tree;

        SegmentTree(const vector<int>& a) {
            n = a.size();
            tree.assign(4 * n, 0);
            build(1, 0, n - 1, a);
        }

        void build(int id, int l, int r, const vector<int>& a) {
            if (l == r) {
                tree[id] = a[l];
                return;
            }
            int mid = (l + r) / 2;
            build(id * 2, l, mid, a);
            build(id * 2 + 1, mid + 1, r, a);
            tree[id] = tree[id * 2] + tree[id * 2 + 1];
        }

        void update(int id, int l, int r, int pos) {
            if (l == r) {
                tree[id] = -1;
                return;
            } 
            int mid = (l + r) / 2;
            if (pos <= mid) update(id * 2, l, mid, pos);
            else update(id * 2 + 1, mid + 1, r, pos);
            tree[id] = max(tree[id], tree[id * 2 + 1]);
        }

        int query(int id, int l, int r, int val) {
            if (tree[id] < val) return -1;
            if (l == r) return l;
            int mid = (l + r) / 2;
            int res = query(id * 2, l, mid, val);
            if (res == -1) res = query(id * 2 + 1, mid + 1, r, val);
            return res;
        }

        int find_first(int val) {
            return query(1, 0, n - 1, val);
        }
        void mark_used(int pos) {
            update(1, 0, n - 1, pos);
        }
    };

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree st(baskets);
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            int pos = st.find_first(fruits[i]);
            if (pos == -1) unplaced++;
            else st.mark_used(pos);
        }
        return unplaced;
    }
};