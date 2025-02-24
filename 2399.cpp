#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstIndex(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (firstIndex[c] == -1) firstIndex[c] = i;
            else {
                int actualDistance = i - firstIndex[c] - 1;
                if (actualDistance != distance[c]) return false;
            }
        }

        return true;
    }
};