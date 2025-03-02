#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        if (word.find(ch) == string::npos) return word;
        reverse(word.begin(), word.begin() + word.find(ch) + 1);
        return word;
    }
};