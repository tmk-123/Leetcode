#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0; // vị trí lưu phần tử hợp lệ tiếp theo
        
        for (int i = 0; i < nums.size(); i++) {
            if (j < 2 || nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }
        
        return j;
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