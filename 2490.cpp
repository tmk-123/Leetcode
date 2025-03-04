#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] != sentence[sentence.length() - 1]) return false;

        while (int i = sentence.find(" ") != string::npos) {
            if (sentence[i - 1] != sentence[i + 1]) return false;
            sentence.erase(i, 1);
        }
        return true;
    }
};