#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> combination;

    vector<vector<int>> combine(int n, int k) {
        Try(1, n, k, 0);
        return res;
    }

    void Try(int index, int n, int k, int cnt) {
        if (cnt == k) {
            res.push_back(combination);
            return;
        }

        for (int i = index; i <= n; i++) {
            combination.push_back(i);
            Try(i + 1, n, k, cnt + 1);
            combination.pop_back();
        }

        return;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Solution sol;
    vector<vector<int>> res = sol.combine(n, k);

    for (auto x : res) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}