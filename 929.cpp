#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> Set;
        for (string& s : emails) {
            int i = s.find("@");
            string t = s.substr(0, i);
            s.erase(0, i);
            while (t.find(".") != string::npos) {
                t.erase(t.find("."), 1);
            }
            while (t.find("+") != string::npos) {
                t.erase(t.find("+"));
            }

            s = t + s;
            Set.insert(s);
        }   
        return Set.size();
    }
};