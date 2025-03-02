#include<bits/stdc++.h>

using namespace std;

class Solution {
public: 
   int numDifferentIntegers(string word) {
        for (char &c : word) {
            if (!isdigit(c)) c = ' ';
        }

        stringstream ss(word);
        string num;
        unordered_set<string> uniqueNumbers;

        while (ss >> num) {
            while (num.size() > 1 && num[0] == '0') {
                num.erase(0, 1);
            }
            uniqueNumbers.insert(num);
        }

        return uniqueNumbers.size();
    }
};