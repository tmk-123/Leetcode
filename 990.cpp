#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int parent[26];

    // tìm gốc 
    int find(int x) {
        if (parent[x] == x) return x;
        
        // gán trực tiếp parent[x] = find(parent[x]), rồi đệ quy đến khi parent[x] == x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) parent[rootY] = rootX;
    }

    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) parent[i] = i;
        
        for (string &e : equations) {
            if (e[1] == '=') {
                int x1 = e[0] - 'a';
                int x2 = e[3] - 'a';    
                unionSet(x1, x2);
            }
        }

        for (string &e : equations) {
            if (e[1] == '!') {
                int x1 = e[0] - 'a';
                int x2 = e[3] - 'a';

                if (find(x1) == find(x2)) return false;
            }
        }
        return true;
    }
};