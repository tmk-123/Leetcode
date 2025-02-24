#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, int> m;
        map<vector<int>, string> S;
        for (string s : words) {
            vector<int> v;
            for (int i = 1; i < s.length(); i++) {
                v.push_back(s[i] - s[i - 1]);
            }
            m[v]++;
            S[v] = s;
        }

        for (auto x : m) {
            if (x.second == 1) {
                return S[x.first];
            }
        }
        return "";
    }
};