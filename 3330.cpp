#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int sum = 1;
        int cnt = 0;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            }
            else {
                sum += cnt;
                cnt = 0;
            }   
        }

        sum += cnt;
        return sum;
    }
};