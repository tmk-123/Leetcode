#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> digitGroup;
        int maxFreq = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int digit = sumDigits(i);
            digitGroup[digit]++;
            maxFreq = max(maxFreq, digitGroup[digit]);
        }

        int maxSize = 0;
        for (auto [digit, freq] : digitGroup) {
            if (freq == maxFreq) maxSize++;
        }
        return maxSize;
    }
};