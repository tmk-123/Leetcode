#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int zeroCount = 0, oneCount = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '0') zeroCount++;
                else oneCount++;

                if (zeroCount <= k || oneCount <= k) {
                    count++;
                } else {
                    break; // Dừng sớm vì nếu hiện tại không thỏa thì các đoạn tiếp theo cũng không thỏa
                }
            }
        }
        
        return count;
    }
};