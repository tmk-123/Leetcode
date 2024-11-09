#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // tránh trùng lặp với phần tử trước đó
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right =  nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    // tránh phần tử trùng nhau
                    while (nums[left] == nums[left + 1] && left < right) {
                        left++;
                    }

                    while (nums[right] == nums[right - 1] && left < right) {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if (sum < 0) left++;
                else right--;
            }
        }
        return res;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);

    for (auto v : res) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
    }
}