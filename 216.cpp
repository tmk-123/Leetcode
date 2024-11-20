#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1);
        return res;
    }

    void backtrack(int k, int n, int index) {
        if (combination.size() > k || n < 0) return;

        if (combination.size() == k && n == 0) {
            res.push_back(combination);
            return;
        }

        for (int i = index; i <= 9; i++) {
            combination.push_back(i);
            backtrack(k, n - i, i + 1);
            combination.pop_back();
        }

        return;
    }
};

int main() {
    int k, n;
    cin >> k >> n;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum3(k, n);

    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}