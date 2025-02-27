#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---","-.-",".-..",
            "--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> Set;
        for (string s : words) {
            string t = "";
            for (char c : s) {
                t += morse[c - 'a'];
            }
            Set.insert(t);
        }

        return Set.size();
    }
};