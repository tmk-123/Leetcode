#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> v;

        while (ss >> word) {
            if (!word.empty()) {
                v.push_back(word);
            }
        } 

        string res;
        for (int i = v.size() - 1; i >= 0; i--) {
            res += v[i];
            res += " ";
        }
        res.pop_back();
        
        return res;
    }
};

int main () {
    string s;
    getline(cin, s) >> s;

    Solution sol;
    cout << sol.reverseWords(s);
}