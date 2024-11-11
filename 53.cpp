#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // nếu a[i] lớn hơn thì sẽ tính dãy con mới từ a[i] trở đi, còn không sẽ hợp nhất với dãy con liên tiếp trước đó
            current_sum = max(nums[i], current_sum + nums[i]);
            maxSum = max(maxSum, current_sum);
        }

        return maxSum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.maxSubArray(nums);
}