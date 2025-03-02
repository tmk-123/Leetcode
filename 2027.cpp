#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int moves = 0;
        int n = s.length();

        // greedy
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') {
                moves++;  
                i += 2;   
            }
        }

        return moves;
    }
}; 