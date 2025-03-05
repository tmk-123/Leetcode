#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxDuration = releaseTimes[0];  // Thời gian nhấn dài nhất
        char maxKey = keysPressed[0];       // Phím có thời gian nhấn dài nhất

        for (int i = 1; i < releaseTimes.size(); i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];  // Tính thời gian nhấn

            if (duration > maxDuration || (duration == maxDuration && keysPressed[i] > maxKey)) {
                maxDuration = duration;
                maxKey = keysPressed[i];
            }
        }

        return maxKey;
    }
};