#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> seenSums;
        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1];  // Tính tổng của subarray có độ dài 2
            if (seenSums.count(sum)) return true;  // Nếu tổng đã xuất hiện, trả về true
            seenSums.insert(sum);  // Lưu tổng vào set
        }
        return false;  // Nếu duyệt hết không tìm thấy, trả về false
    }
};