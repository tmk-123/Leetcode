#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        string res = "";
        stringstream ss(title);
        string word;

        while (ss >> word) {
            if (word.length() < 3) {
                for (char &c : word) c = tolower(c); 
            } 
            else {
                word[0] = toupper(word[0]);
                for (int i = 1; i < word.length(); i++) word[i] = tolower(word[i]);
            }
            res += word + " ";
        }

        res.pop_back();
        return res;
    }
};