#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return string::npos == s.find("01");
    }
};