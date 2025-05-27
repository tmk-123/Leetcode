#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    bool found = false;
    vector<int> ans;

    bool check(int a, int b) {
        int cnt = 0;
        for (int i = 0; i < 16; i++) {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            if (x != y) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }

    void Try(int n, vector<int> res) {
        if (found) return;
        if (res.size() == (1 << n)) {
            ans = res;
            found = true;
            return;
        }

        for (int i = 1; i < (1 << n); i++) {
            if (!visited[i] && check(i, res.back())) {
                visited[i] = true;
                res.push_back(i);
                Try(n, res);
                res.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<int> grayCode(int n) {
        visited.assign((1 << n), false);
        vector<int> res;
        res.push_back(0);
        Try(n, res);
        return ans;
    }
};