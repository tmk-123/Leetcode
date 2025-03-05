#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (string &s : commands) {
            if (s == "UP") i--;
            else if (s == "DOWN") i++;
            else if (s == "RIGHT") j++;
            else j--;
        }

        return i * n + j;
    }
};