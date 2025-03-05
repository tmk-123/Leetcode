#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int chair = 0, maxChair = 0;
        for (char& c : s) {
            if (c == 'E') chair++;
            else chair--;

            maxChair = max(maxChair, chair);
        }
        return maxChair;
    }
};  