#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return solve(0, s, seen);
    }

    int solve(int start, string& s, unordered_set<string>& seen) {
        if (start == s.size()) return 0;
        
        int maxSplits = 0;
        for (int end = start + 1; end <= s.size(); end++) {
            string substr = s.substr(start, end - start);
            if (!seen.count(substr)) {
                seen.insert(substr);
                maxSplits = max(maxSplits, 1 + solve(end, s, seen));
                seen.erase(substr);
            }
        }

        return maxSplits;
    }
};
