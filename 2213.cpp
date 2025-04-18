#include<bits/stdc++.h>

using namespace std;

struct Node {
    int lChar, rChar; // ký tự đầu và cuối theo ascii
    int lLen, rLen; // độ dài ký tự liên tiếp từ trái và phải, để trái phần này gộp phải phần kia
    int maxLen;
};

class SegmentTree {
public:
    int n;
    string s;
    vector<Node> tree;

    SegmentTree(string& str) {
        s = str;
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);   
    }

    void build(int id, int l, int r) {
        if (l == r) {
            int ch = s[l];
            tree[id] = {ch, ch, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = merge(tree[id * 2], tree[id * 2 + 1], mid - l + 1, r - mid);
    }

    Node merge(Node& a, Node& b, int lenA, int lenB) {
        Node res;
        res.lChar = a.lChar;
        res.rChar = b.rChar;

        // nếu cả đoạn a(left) hoặc b(right) đều là ký tự giống nhau
        res.lLen = (a.lLen == lenA && a.rChar == b.lChar) ? a.lLen + b.lLen : a.lLen;
        res.rLen = (b.rLen == lenB && a.rChar == b.lChar) ? a.rLen + b.rLen : b.rLen;

        // maxLen = max(max Trái, max Phải, nối cuối a, đầu b) 
        res.maxLen = max({a.maxLen, b.maxLen, (a.rChar == b.lChar ? a.rLen + b.lLen : 0)});
        return res;
    }

    // update ký tự tại pos thành val
    void update(int id, int l, int r, int pos, char val) {
        if (l == r) {
            tree[id] = {val, val, 1, 1, 1};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(id * 2, l, mid, pos, val);
        else update(id * 2 + 1, mid + 1, r, pos, val);

        tree[id] = merge(tree[id * 2], tree[id * 2 + 1], mid - l + 1, r - mid);
    }

    int getMaxLen() {
        return tree[1].maxLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree seg(s);
        vector<int> res;
        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            seg.update(1, 0, s.size() - 1, pos, ch);
            res.push_back(seg.getMaxLen());
        }    
        return res;
    }
};