#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool> (numCourses, false));

        for (auto& pre : prerequisites) {
            reachable[pre[0]][pre[1]] = true;
        }

        // floyd-warshall
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(reachable[q[0]][q[1]]);
        }
        return res;
    }
};