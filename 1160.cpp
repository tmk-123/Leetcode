#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};
        for (char c : chars) {
            freq[c - 'a']++;
        }

        int sumLength = 0;
        for (const string& word : words) {
            int temp[26] = {0};
            for (char c : word) {
                temp[c - 'a']++;
            }
            
            bool isGood = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] > freq[i]) {
                    isGood = false;
                    break;
                }
            }
            
            if (isGood) {
                sumLength += word.size();
            }
        }
        return sumLength;
    }
};

int main() {
    vector<string> word = {"cat","bt","hat","tree"};
    string chars = "atach";
    Solution sol;
    cout << sol.countCharacters(word, chars);
}