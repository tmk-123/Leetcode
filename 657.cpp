#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for (char c : moves) {
            if (c == 'U') i++;
            else if (c == 'D') i--;
            else if (c == 'L') j++;
            else j--; 
        }

        if (i == 0 && j == 0) return true;
        return false;
    }
};