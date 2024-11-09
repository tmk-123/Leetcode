#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = 1e5;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                closestSum = abs(closestSum - target) > abs(sum - target) ? sum : closestSum;
                if (sum < target) left++;
                else if (sum > target) right--;
                else return sum;
            }
        }

        return closestSum;
    }
};

int main() {
    int t, n;
    vector<int> nums;
    
    cin >> t;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.threeSumClosest(nums, t);
}