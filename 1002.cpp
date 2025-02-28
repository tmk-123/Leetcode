#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> letters(26, INT_MAX);
        for (string s : words) {
            vector<int> v(26, 0);
            for (char c : s) {
                v[c - 'a']++;
            }
            
            for (int i = 0; i < 26; i++) {
                letters[i] = min(v[i], letters[i]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < letters[i]; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};