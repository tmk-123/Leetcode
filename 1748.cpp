#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Đếm số lần xuất hiện của mỗi phần tử
        for (int num : nums) {
            freq[num]++;
        }
        
        int sum = 0;
        // Tính tổng các phần tử xuất hiện đúng một lần
        for (auto& [num, count] : freq) {
            if (count == 1) {
                sum += num;
            }
        }
        
        return sum;
    }
};