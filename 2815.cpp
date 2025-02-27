#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDigit(int n) {
        int digit = 0;
        while (n > 0) {
            digit = max(digit, n % 10);
            n /= 10;
        }
        return digit;
    }

    int maxSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int n : nums) {
            int x = maxDigit(n);
            m[x].push_back(n);
        }

        int max_sum = -1;
        for (auto& [n, v] : m) {  // Duyệt qua từng nhóm số có cùng chữ số lớn nhất
            if (v.size() < 2) continue;
            sort(v.rbegin(), v.rend());  // Sắp xếp giảm dần
            max_sum = max(max_sum, v[0] + v[1]);  // Lấy tổng lớn nhất của 2 số đầu tiên
        }

        return max_sum;
    }
};
