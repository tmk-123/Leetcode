#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        for (int i = 0; i <= n - k; i++) {
            char c = s[i];
            bool allSame = true;
            for (int j = i; j < i + k; j++) {
                if (s[j] != c) {
                    allSame = false;
                    break;
                }
            }
            
            // Nếu đoạn con hợp lệ, kiểm tra điều kiện biên
            if (allSame) {
                if ((i == 0 || s[i - 1] != c) && (i + k == n || s[i + k] != c)) {
                    return true;
                }
            }
        }
        return false;
    }
};