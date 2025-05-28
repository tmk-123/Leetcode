#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBuckets(string hamsters) {
        if (hamsters == "H") return -1;
        if (hamsters == ".") return 0;
        if (hamsters.substr(0, 2) == "HH" || hamsters.substr(hamsters.size() - 2, 2) == "HH") return -1;
        if (hamsters.find("HHH") != string::npos) return -1;
        
        int cnt = 0;
        for (int i = 0; i < hamsters.size(); i++) {
            if (hamsters[i] == 'H') cnt++;
        }

        for (int i = 1; i < hamsters.size() - 1; i++) {
            if (hamsters[i] == '.' && hamsters[i + 1] == 'H' && hamsters[i - 1] == 'H') {
                cnt--;
                i += 2;
            }
        }
        return cnt;
    }
};