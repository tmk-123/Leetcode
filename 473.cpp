#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLength % 4 != 0) return false;
        int sideLength = totalLength / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        
        return backtrack(matchsticks, sides, 0, sideLength);
    }
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int index, int sideLength) {
        if (index == matchsticks.size()) {
            return sides[0] == sideLength && sides[1] == sideLength && 
                   sides[2] == sideLength && sides[3] == sideLength;
        }

        for (int i = 0; i < 4; i++) {
            if (matchsticks[index] > sideLength) return false;
            if (sides[i] + matchsticks[index] > sideLength) continue;

            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, sides, index + 1, sideLength)) return true;
            sides[i] -= matchsticks[index];

            if (sides[i] == 0) break;
        }

        return false;
    }
};

int main() {
    int n;
    vector<int> matchsticks;
    while (cin >> n) {
        matchsticks.push_back(n);
    }

    Solution sol;
    cout << sol.makesquare(matchsticks);
}