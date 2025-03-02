#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        if (s.find("a") == string::npos || s.find("b") == string::npos) return true; 
        int lastA = s.rfind("a");
        int firstB = s.find("b");
        if (lastA > firstB) return false;
        return true;
    }
};