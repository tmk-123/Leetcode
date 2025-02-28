#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for (char c : text) {
            m[c]++;
        }

        if (m.find('b') == m.end() || m.find('a') == m.end() || m.find('n') == m.end() ||
            m.find('l') == m.end() || m.find('o') == m.end()) return 0;
            
        int maxBalloon = INT_MAX;
        for (auto [c, freq] : m) {
            if (c == 'b' || c == 'a' || c == 'n') maxBalloon = min(freq, maxBalloon);
            else if (c == 'l' || c == 'o') maxBalloon = min(freq / 2, maxBalloon);
        }

        return maxBalloon;
    }
};