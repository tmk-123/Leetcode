#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);  // Vì số từ tối đa là 9
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            int pos = word.back() - '0';  // Lấy số thứ tự (1-9)
            words[pos - 1] = word.substr(0, word.size() - 1);  // Lưu từ vào đúng vị trí
        }
        
        string result;
        for (int i = 0; i < 9 && !words[i].empty(); i++) {
            if (!result.empty()) result += " ";
            result += words[i];
        }
        
        return result;
    }
};