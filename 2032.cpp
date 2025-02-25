#include<bits/stdc++.h>

using namespace std;
class Solution {
    public:
        int countBits(int n) {
        int count = 0;
        while (n) {         // Lặp đến khi n = 0
            count += (n & 1); // Kiểm tra bit cuối (nếu là 1 thì tăng count)
            if (count >= 2) return count; // Nếu >= 2 thì dừng sớm
            n >>= 1;        // Dịch phải để kiểm tra bit tiếp theo
        }
        return count;
    }
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mask;
        
        // Gán bitmask cho từng phần tử xuất hiện trong mỗi mảng
        for (int num : nums1) mask[num] |= (1 << 0);
        for (int num : nums2) mask[num] |= (1 << 1);
        for (int num : nums3) mask[num] |= (1 << 2);
    
        vector<int> result;
        for (auto [num, bitmask] : mask) {
            if (countBits(bitmask) >= 2) { // Kiểm tra xem số bit 1 có ≥ 2 hay không
                result.push_back(num);
            }
        }
        return result;
    }
    
    };