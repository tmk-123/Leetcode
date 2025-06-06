#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            // xóa để max tăng dần, min giảm dần để lấy max, min 
            while (!maxDeque.empty() && maxDeque.back() < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);

            while (!minDeque.empty() && minDeque.back() > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[left]) maxDeque.pop_front();
                if (minDeque.front() == nums[left]) minDeque.pop_front();
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
