#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> Set;
        for (char c : word) Set.insert(c);

        int cnt = 0;
        for (char c : Set) {
            if ('a' <= c && c <= 'z' && Set.find(c - 'a' + 'A') != Set.end()) cnt++;
        }
        return cnt;
    }
};