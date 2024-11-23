#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        int cnt = 0;
        int currentLength = 0;

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                currentLength++;

                // với mỗi phần tử thêm vào dãy con số học ta có thêm currentLength dãy con mới
                // (bao gồm các dãy kết thúc tại phần tử đó)
                cnt += currentLength;
            }
            else {
                currentLength = 0;
            }
        }

        return cnt;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.numberOfArithmeticSlices(nums);
}