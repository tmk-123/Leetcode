#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1, v2;
        v1 = formatStr(version1);
        v2 = formatStr(version2);

        while (v2.size() < v1.size()) {
            v2.push_back("0");
        }
        while (v1.size() < v2.size()) {
            v1.push_back("0");
        }
        
        for (int i = 0; i < v1.size(); i++) {
            if (stoi(v1[i]) < stoi(v2[i])) return -1;
            if (stoi(v1[i]) > stoi(v2[i])) return 1;
        }

        return 0;
    }

    vector<string> formatStr(string s) {
        stringstream ss(s);
        string word;
        vector<string> v;

        while (getline(ss, word, '.')) {
            int i = 0;
            while (word[i] == '0' && i < word.length()) {
                word.erase(0, 1);
            }
            if (!word.empty()) v.push_back(word);
            else v.push_back("0");
        }
        
        return v;
    }
};

int main() {
    string v1, v2;
    cin >> v1 >> v2;
    Solution sol;
    cout << sol.compareVersion(v1, v2);
}