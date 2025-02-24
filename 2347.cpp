#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (suits[0] == suits[1] && suits[1] == suits[2] && 
            suits[2] == suits[3] && suits[3] == suits[4]) return "Flush";
        
        unordered_map<int, int> m;
        int Pair = false;
        for (int r : ranks) {
            m[r]++;
            if (m[r] == 2) Pair = true;
            if (m[r] == 3) return "Three of a Kind";
        }
        if (Pair) return "Pair";
        return "High Card";
    }
};