#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";

        for (string s : words) {
            char c = s[0];
            if (c >= 'A' && c <= 'Z') c = tolower(c);
            if ((s1.find(c) != string::npos && check(s, s1)) ||
                (s2.find(c) != string::npos && check(s, s2)) ||
                (s3.find(c) != string::npos && check(s, s3))) 
                {
                    res.push_back(s);
                }
        }
        return res;
    }

    bool check(string s, string row) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
            if (row.find(s[i]) == string::npos) return false;
        }
        return true;
    }
};

int main() {
    vector<string> v = {"Hello","Alaska","Dad","Peace"};
    Solution sol;
    vector<string> res = sol.findWords(v);
    for (string s : res) cout << s << " ";
    cout << endl;
}