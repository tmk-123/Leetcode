    #include<bits/stdc++.h>

    using namespace std;

    class Solution {
    public:
        bool checkTwoChessboards(string coordinate1, string coordinate2) {
            if (abs(coordinate1[0] - coordinate2[0]) % 2 == (abs(coordinate1[1] - coordinate2[1]) % 2)) return true;
            return false;
        }
    };