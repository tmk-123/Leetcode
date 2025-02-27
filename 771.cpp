#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int count = 0;
        for (char c : stones) {
            if (jewelSet.count(c)) { 
                count++;
            }
        }
        return count;
    }
};