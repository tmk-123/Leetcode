#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string token;
        int last = INT_MIN;
        while (ss >> token) {
            if (isdigit(token[0])) {
                int n = stoi(token);
                if (n <= last) return false;
                last = n;
            }
        }
        return true;
    }
};