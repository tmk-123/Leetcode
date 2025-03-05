#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes = 0, maxZeros = 0;
        int count = 0, n = s.size();
        
        // Tìm đoạn liên tiếp dài nhất của '1'
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
                maxOnes = max(maxOnes, count);
            } else {
                count = 0;
            }
        }
        
        count = 0;
        // Tìm đoạn liên tiếp dài nhất của '0'
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                count++;
                maxZeros = max(maxZeros, count);
            } else {
                count = 0;
            }
        }
        
        return maxOnes > maxZeros;
    }
};