#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index = (ruleKey == "type") ? 0 : (ruleKey == "color") ? 1 : 2;
        int count = 0;
        
        for (const auto& item : items) {
            if (item[index] == ruleValue) {
                count++;
            }
        }
        
        return count;
    }
};