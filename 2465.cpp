#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> sum;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            sum.insert(nums[left] + nums[right]);
        }
        return sum.size();
    }
};

int main() {

}