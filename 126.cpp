#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    }
};

int main() {
    string beginWord, endWord, s;
    cin >> beginWord >> endWord;
    vector<string> wordList;
    while (cin >> s) {
        wordList.push_back(s);
    }

    Solution sol;
    vector<vector<string>> res = sol.findLadders(beginWord, endWord, wordList);
    for (auto x : res) {
        for (auto str : x) {
            cout << str << " ";
        }
        cout << endl;
    }
}