#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int unequalTriplets(vector<int>& nums) {
            int c = 0;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i; j < nums.size(); j++) {
                    for (int k = j; k < nums.size(); k++) {
                        if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]){
                            c++;
                        }
                    }
                }
            }
            return c;
        }
    };

int main() {
    vector<int> v = {4,4,2,4,3};
    Solution sol;
    cout << sol.unequalTriplets(v);
}