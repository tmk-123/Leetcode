#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string &s : operations) {
            s.erase(s.find("X"), 1);
            if (s == "--") x--;
            else x++;
        }
        return x;
    }
};