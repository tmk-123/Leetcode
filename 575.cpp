#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> Set(candyType.begin(), candyType.end());
        if (Set.size() < candyType.size() / 2) return Set.size();
        return candyType.size() / 2;
    }
};