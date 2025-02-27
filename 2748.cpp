#include<bits/stdc++.h>

using namespace std;

int getFirstDigit(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

int getLastDigit(int n) {
    return n % 10;
}

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int firstDigit = getFirstDigit(nums[i]); // Chữ số đầu tiên của nums[i]
            for (int j = i + 1; j < n; j++) {
                int lastDigit = getLastDigit(nums[j]); // Chữ số cuối cùng của nums[j]
                if (__gcd(firstDigit, lastDigit) == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

