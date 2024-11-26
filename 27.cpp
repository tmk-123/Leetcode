#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        if (nums.size() == 1 && val == nums[0]) return 0;

        while (i <= j) {
            while (j >= 0 && nums[j] == val) j--;
            if (i > j) break;

            if (nums[i] == val) swap(nums[i], nums[j]);
            i++;
        }

        return i;
    }
};

int main() {
    int val;
    cin >> val;
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    cout << sol.removeElement(nums, val);
}

// int k = 0;

// for (int i = 0; i < nums.size(); i++) {
//     if (nums[i] != val) {
//         nums[k] = nums[i];
//         k++;
//     }
// }

// return k;  