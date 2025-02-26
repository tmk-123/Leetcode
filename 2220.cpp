#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while (start > 0 && goal > 0) {
            if ((start & 1) != (goal & 1)) cnt++;
            start >>= 1;
            goal >>= 1;
        }   

        while (start > 0) {
            if ((start & 1) == 1) cnt++;
            start >>= 1;
        }
        while (goal > 0) {
            if ((goal & 1) == 1) cnt++;
            goal >>= 1;
        }
        return cnt;
    }
};