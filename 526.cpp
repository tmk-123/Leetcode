#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<bool> used(n + 1, 0);
        return backtrack(used, 1, n);
    }

    int backtrack(vector<bool>& used, int index, int n) {
        if (index > n) {
            return 1;
        }

        int cnt = 0;
        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % index == 0 || index % num == 0)) {
                used[num] = true;
                cnt += backtrack(used, index + 1, n);
                used[num] = false;
            }
        }

        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.countArrangement(n);
}