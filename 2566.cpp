#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] < '9') {
                for(int j = i+1; j < s.length(); j++)
                    if(s[i] == s[j])
                        s[j] = '9';
                s[i] = '9';
                break;
            }
        }
        int max = stoi(s);
        s = to_string(num);
        for(int i = 0; i < s.length(); i++) {
            if(s[i] > '0') {
                for(int j = i+1; j < s.length(); j++)
                    if(s[i] == s[j])
                        s[j] = '0';
                s[i] = '0';
                break;
            }
        }
        return max - stoi(s);
    }
};