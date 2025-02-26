#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        for (int len = 1; len <= n; len++) {
            int OrAll = 0;
            for (int i = 0; i < len; i++) OrAll |= nums[i];
            if (OrAll >= k) return len;

            for (int i = len; i < n; i++) {
                OrAll |= nums[i];
            
                // Cần tính lại OR vì không thể "bỏ" bit bằng cách loại nums[i - len]
                OrAll = 0;
                for (int j = i - len + 1; j <= i; j++) {
                    OrAll |= nums[j];
                }
                if (OrAll >= k) return len;
            }
        }
        return -1;
    }
};


int main() {
    cout << (((32 ^ 1 )^ 25 )^ 11) ;
}
