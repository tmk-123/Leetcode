#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string s;
        backtrack(digits, s, 0);
        return res;
    }

    void backtrack(string &digits, string &s, int index){
        if (index == digits.size()){
            res.push_back(s);
            return;
        }

        string letters = v[digits[index] - '0'];
        for (char letter : letters){
            s.push_back(letter);
            backtrack(digits, s, index + 1);
            s.pop_back();
        }
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    vector<string> res = sol.letterCombinations(s);

    for (auto str : res){
        cout << str << " ";
    }
}