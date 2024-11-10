#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int k = 0; k < nums.size() - 3; k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;

            for (int i = k + 1; i < nums.size() - 2; i++) {
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;

                int left = i + 1, right =  nums.size() - 1;

                while (left < right) {
                    long long sum = (long long) nums[k] + nums[i] + nums[left] + nums[right];

                    if (sum == target) {
                        res.push_back({nums[k], nums[i], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }

        return res;
    }
};

int main() {
    int t, n;
    cin >> t;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    vector<vector<int>> res = sol.fourSum(nums, t);

    for (auto x : res) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}