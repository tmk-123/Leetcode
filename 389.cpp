#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char Xor = 0;
        for (char c : s) {
            Xor ^= c;
        }
        for (char c : t) {
            Xor ^= c;
        }

        return Xor;
    }
};

int main() {
    Solution sol;
    cout << sol.findTheDifference("abcd", "abcde");
}