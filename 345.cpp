#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        string t = "aeouiAEOUI";
        while (left < right) {
            cout << s[left] << " " << s[right] << endl;
            if (t.find(s[left]) != string::npos && t.find(s[right]) != string::npos) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if (t.find(s[left]) == string::npos) left++;
            else right--;
        }
        return s;
    }
};