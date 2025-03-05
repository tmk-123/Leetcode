#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int i = 0, cnt = 0;
        for (char c : moves) {
            if (c == 'L') i--;
            else if (c == 'R') i++;
            else cnt++;
        }

        return abs(i) + cnt;
    }
};