#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) return -1;

        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (out[i] == 0 && in[i] == n - 1) return i;
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> v = {
        {1, 3},
        {2, 3},
    };

    Solution sol;
    cout << sol.findJudge(3, v);
}