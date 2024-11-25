#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return backtrack(nums);
    }

    bool backtrack(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    // tạo vector gồm các phần tử khác
                    vector<double> remaining;
                    for (int k = 0; k < nums.size(); k++) {
                        if (k != i && k != j) {
                            remaining.push_back(nums[k]);
                        }
                    }

                    remaining.push_back(nums[i] + nums[j]);
                    if (backtrack(remaining)) return true;
                    
                    remaining.back() = nums[i] - nums[j];
                    if (backtrack(remaining)) return true;

                    remaining.back() = nums[i] * nums[j];
                    if (backtrack(remaining)) return true;

                    if (nums[j] != 0) {
                        remaining.back() = nums[i] / nums[j];
                        if (backtrack(remaining)) return true;
                    }
                }
            }
        }
        
        return false;
    }
};

int main() {
    vector<int> cards(4);
    for (int i = 0; i < 4; i++) cin >> cards[i];
    Solution sol;
    cout << sol.judgePoint24(cards);
}