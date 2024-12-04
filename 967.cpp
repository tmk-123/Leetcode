#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            dfs(n - 1, k, i, res);
        }
        return res;
    }

    void dfs(int len, int k, int current, vector<int>& res) {
        if (len == 0) {
            res.push_back(current);
            return;
        }
        
        int last_digit = current % 10;
        if (k + last_digit < 10) {
            dfs(len - 1, k, current * 10 + last_digit + k, res);
        }
        // k = 0 sẽ bị trùng
        if (k > 0 && last_digit - k >= 0) {
            dfs(len - 1, k, current * 10 + last_digit - k, res);
        }

        return;
    } 
};

int main() {
    int n, k;
    cin >> n >> k;
    Solution sol;
    vector<int> res = sol.numsSameConsecDiff(n, k);
    for (int x : res) {
        cout << x << " ";
    }
}