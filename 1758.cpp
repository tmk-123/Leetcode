#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int change1 = 0, change2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] != (i % 2 == 0 ? '0' : '1')) 
                change1++;  // Biến đổi để thành "010101..."
            
            if (s[i] != (i % 2 == 0 ? '1' : '0')) 
                change2++;  // Biến đổi để thành "101010..."
        }
        
        return min(change1, change2);
    }
};