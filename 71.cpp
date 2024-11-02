#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path.erase(0, 1);
        stringstream ss(path);
        string word;
        vector<string> v;
        int cnt = 0;
        

        while (getline(ss, word, '/')) {
            if (!word.empty()) {
                if (word == "..") {
                    if (!v.empty()) v.pop_back();
                }
                else if (word != ".") v.push_back(word);
            }
        }

        string res;
        if (v.empty()) res = "/";
        else {
            for (auto x : v) {
                res += "/";
                res += x;
            }
        }

        return res;
    }
};

int main () {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.simplifyPath(s);
}