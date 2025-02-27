#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt = 0;
        unordered_set<string> m;
        for (string s : words) {
            string t = s;
            reverse(t.begin(), t.end());
            if (m.find(t) != m.end()) {
                cnt++;
                m.erase(t);
            }
            else m.insert(s);
        }
        return cnt;
    }
};