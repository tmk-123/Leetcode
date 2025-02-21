#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN, secondLargest = INT_MIN, index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
                index = i;
            }
            else if (nums[i] > secondLargest) secondLargest = nums[i];
        }

        if (largest >= 2 * secondLargest) return index;
        return -1;
    }
};

int main() {
    vector<int> v = {3, 6, 1, 0};
    Solution sol;
    cout << sol.dominantIndex(v);
}