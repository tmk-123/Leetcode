#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
    
        for (int num : nums) {
            if (count == 0) {
                candidate = num;  // Cập nhật ứng viên, trừ hết count 
            }

            // nếu gặp số khác thì trừ
            count += (num == candidate) ? 1 : -1; 
        }
        
        return candidate;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.majorityElement(nums);
}