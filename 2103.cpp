#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        unordered_set<char> B, R, G;
        for (int i = 0; i < rings.size(); i += 2) {
            if (rings[i] == 'B') B.insert(rings[i + 1]);
            else if (rings[i] == 'R') R.insert(rings[i + 1]);
            else G.insert(rings[i + 1]);
        }

        int cnt = 0;
        for (char c = '0'; c <= '9'; c++) {
            if (B.find(c) != B.end() && R.find(c) != R.end() && G.find(c) != G.end()) cnt++;
        }
        return cnt;
    }
};