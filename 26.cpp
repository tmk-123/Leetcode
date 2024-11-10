#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 1;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i - 1]) {
                // vì mảng đã cho không giảm
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.removeDuplicates(nums);
}