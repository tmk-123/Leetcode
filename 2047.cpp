#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(string s) {
        if (s.length() == 1) {
            if (s == "-") return false;
            if (!isdigit(s[0])) return true;
        }

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) return false;
            if (i != s.length() - 1 && (s[i] == ',' || s[i] == '!' || s[i] == '.')) return false;
        }

        if (s.find("-") != string::npos) {
            int i = s.find("-");
            if (i == 0 || i == s.length() - 1) return false;
            if (!isalpha(s[i - 1]) || !isalpha(s[i + 1])) return false;
            s.erase(i, 1);
            if (s.find("-") != string::npos) return false;
        }
        return true;
    }
    int countValidWords(string sentence) {
        int cnt = 0;
        stringstream ss(sentence);
        string s;
        while (ss >> s) {
            if (check(s)) {
                cout << s << " ";
                cnt++;
            }
        }
        return cnt;
    }
};