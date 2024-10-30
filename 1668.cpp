#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int cnt = 0, n = sequence.length();
        string temp = word;
        while (sequence.find(temp) != string::npos){
            temp += word;
            cnt++;
        }

        return cnt;
    }
};
int main() {
    string s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    cout << sol.maxRepeating(s1, s2);
}