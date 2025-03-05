#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
    
        for (int i = 0; i < n - 1; i++) {
            if ((s[i] % 2) == (s[i + 1] % 2) && s[i] > s[i + 1]) {
                swap(s[i], s[i + 1]);
                return s; // Chỉ thực hiện 1 lần đổi chỗ
            }
        }
        
        return s;
    }
};