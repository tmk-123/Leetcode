#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> unique_chars(s.begin(), s.end());
        return unique_chars.size();
    }
};
