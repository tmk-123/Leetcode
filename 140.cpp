#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<string> dict;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) dict.insert(word);
        vector<string> res;
        recursion(s, 0, "", res);
        return res;
    }

    void recursion(string s, int begin, string current, vector<string>& res) {
        if (begin == s.length()) {
            if (current[0] == ' ') current = current.substr(1);
            res.push_back(current);
            return;
        }

        // thêm từng chữ cái vào temp xem có trong dict không
        string temp = "";
        for (int i = begin; i < s.length(); i++) {
            temp.push_back(s[i]);
            if (dict.count(temp)) {
                recursion(s, i + 1, current + " " + temp, res);
            }
        }
    }
};
int main() {
    string s;
    cin >> s;
    string word;
    vector<string> wordDict;
    while (cin >> word) {
        wordDict.push_back(word);
    }
    Solution sol;
    vector<string> res = sol.wordBreak(s, wordDict);
    for (string str : res) {
        cout << str << endl;
    }
}