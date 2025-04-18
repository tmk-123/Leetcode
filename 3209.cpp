#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        return countAtLeastK(nums, k) - countAtLeastK(nums, k + 1);
    }

    long long countAtLeastK(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        vector<int> bitCount(32, 0);

        int left = 0;
        for (int right = 0; right < n; right++) {
            // cập nhập nums[right]
            for (int i = 0; i < 32; i++) {
                if ((nums[right] >> i) & 1) bitCount[i]++;
            }

            // nếu đoạn hiện tại [left -> right] có AND nhỏ hơn k thì co left lại
            while (left <= right && calcAND(bitCount, right - left + 1) < k) {
                for (int i = 0; i < 32; i++) {
                    if ((nums[left] >> i) & 1) {
                        bitCount[i]--;
                    }
                }
                left++;
            }

            ans += (right - left + 1); // tất cả đoạn tại left->right đến right đều thỏa mãn
        }

        return ans;
    }
    int calcAND(vector<int>& bitCount, int width) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            // vì không phải tất cả bit từ left đến right tại i không bằng 1 thì AND = 0 
            if (bitCount[i] == width) {
                res |= (1 << i);
            }
        }
        return res;
    }   
};