#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0);
        unordered_set<long long> edgeSet;

        for (auto& e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
            edgeSet.insert( min(e[0], e[1]) * 1e5 + max(e[0], e[1]) );
        }

        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 == 1) v.emplace_back(i);
        }  

        if (v.size() == 0) return true;
        if (v.size() == 2) {
            int a = v[0], b = v[1];
            if (!edgeSet.count(min(a, b) * 1e5 + max(a, b))) return true; // nếu nối được với nhau

            // thử nối cả a và b với 1 đỉnh khác
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b && 
                    !edgeSet.count(min(a, i) * 1e5 + max(a, i)) &&
                    !edgeSet.count(min(b, i) * 1e5 + max(b, i))) {
                        return true;
                    }
            }

            return false;
        }

        if (v.size() == 4) {
            return check(v[0], v[1], v[2], v[3], edgeSet) ||
                   check(v[0], v[2], v[1], v[3], edgeSet) ||
                   check(v[0], v[3], v[1], v[2], edgeSet);
        }
    }

    bool check(int a, int b, int c, int d, unordered_set<long long>& edgeSet) {
        long long k1 = min(a, b) * 1e5 + max(a, b);
        long long k2 = min(c, d) * 1e5 + max(c, d);
        return !edgeSet.count(k1) && !edgeSet.count(k2);
    }
};