#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(n + 1, 10000);
        nums[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sqrt(i); j++) {
                nums[i] = min(nums[i - j * j] + 1, nums[i]);        
            }
        }

        return nums[n];
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.numSquares(n);
}