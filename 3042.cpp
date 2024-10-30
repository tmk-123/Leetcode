#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() < words[j].length() && isPrefixAndSuffix(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }

    int isPrefixAndSuffix(string s1, string s2) {
        if (s2.find(s1) == 0 && s2.rfind(s1) == s2.length() - s1.length()){
            return true;
        }
        return false;
    }
};

int main() {
    vector<string> v;
    string word;

    while (cin >> word){
        v.push_back(word);
    }

    Solution sol;
    cout << sol.countPrefixSuffixPairs(v);
}   