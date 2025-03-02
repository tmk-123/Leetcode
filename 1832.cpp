#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> m;
        for (char c : sentence) m[c]++;

        for (char c = 'a'; c <= 'z'; c++) {
            if (m[c] == 0) return false;
        }
        return true;
    }
};