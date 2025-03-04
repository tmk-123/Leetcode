#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int minDis = INT_MAX;
        int n = words.size();

        for (int i = 0; i < words.size(); i++) {
            if (words[i] == target) {
                minDis = min({minDis, (startIndex + i) % n, (startIndex - i + n) % n});
            }
        }

        if (minDis == INT_MAX) return -1;
        return minDis;
    }
};