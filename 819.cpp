#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> ban(banned.begin(), banned.end());

        int maxFreq = INT_MIN;
        string res = "";
        string s = "";
        for (int i = 0; i < paragraph.length(); i++) {
            if (isalpha(paragraph[i])) {
                s += tolower(paragraph[i]);
            }
            else {
                if (s == "") continue;
                if (ban.find(s) == ban.end()) {
                    m[s]++;
                    if (m[s] > maxFreq) {
                        maxFreq = m[s];
                        res = s;
                    }
                }
                s = "";
            }
        }

        // nếu k có dấu câu
        if (!s.empty() && ban.find(s) == ban.end()) {
            m[s]++;
            if (m[s] > maxFreq) {
                maxFreq = m[s];
                res = s;
            }
        }
        return res;
    }
};