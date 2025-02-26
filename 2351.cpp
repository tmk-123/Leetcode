#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for (int i = 0; i < s.length(); i++) {
            if ( (mask & (1 << (s[i] - 'a'))) != 0) return s[i];
            mask |= (1 << (s[i] - 'a'));
        }
        return 0;
    }
};