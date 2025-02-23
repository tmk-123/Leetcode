#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            unordered_map<int, int> m;
            for (int j = 0; j < n; j++) {
                m[matrix[i][j]]++;
                if (m[matrix[i][j]] == 1) cnt++;
            }

            if (cnt != n) return false;
        }

        for (int j = 0; j < n; j++) {
            int cnt = 0;
            unordered_map<int, int> m;
            for (int i = 0; i < n; i++) {
                m[matrix[i][j]]++;
                if (m[matrix[i][j]] == 1) cnt++;
            }

            if (cnt != n) return false;
        }

        return true;
    }
};