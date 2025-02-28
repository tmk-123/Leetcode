#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> Set;
        for (int i = 0; i < s.length() - 1; i++) {
            Set.insert(s.substr(i, 2));
        }

        reverse(s.begin(), s.end());
        for (int i = 0; i < s.length() - 1; i++) {
            if (Set.find(s.substr(i, 2)) != Set.end()) return true;
        }
        return false;
    }
};