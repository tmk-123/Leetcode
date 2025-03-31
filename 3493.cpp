#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parent, r;

    int intersect(bitset<101>& a, bitset<101>& b) {
        return (a & b).count();
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool dsu(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        if (r[pu] > r[pv]) parent[pv] = pu;
        else if (r[pu] < r[pv]) parent[pu] = pv;
        else {
            parent[pv] = pu;
            r[pu]++;
        }
        return true;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> adj(n);

        vector<bitset<101>> a(n, 0);
        int i = 0;
        for (auto& p : properties) {
            for (int& x : p) {
                a[i][x] = 1;
            }
            i++;
        }

        r.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(a[i], a[j]) >= k) {
                    components -= dsu(i, j);
                }
            }
        }
        return components;
    }
};