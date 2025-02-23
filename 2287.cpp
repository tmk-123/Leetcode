#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<int, int> m1, m2;
        for (char c : s) m1[c]++;
        for (char c : target) m2[c]++;

        int minCopies = INT_MAX;
        for (char c : target) {
            minCopies = min(minCopies, m1[c] / m2[c]);
        }
        return minCopies;
    }
};