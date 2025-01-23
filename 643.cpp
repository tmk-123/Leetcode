#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int currSum = 0;

        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }

        double maxAverage = currSum * 1.0 / k;
        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i] - nums[i - k];
            maxAverage = max(maxAverage, currSum * 1.0 / k);
        }

        return maxAverage;
    }
};
int main() {
    vector<int> v = {1,12,-5,-6,50,3};
    Solution sol;
    cout << sol.findMaxAverage(v, 4);
}