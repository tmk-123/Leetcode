#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        if (current > correct) swap(current, correct);
        int h1 = stoi(current.substr(0, 2)), m1 = stoi(current.substr(3, 2));
        int h2 = stoi(correct.substr(0, 2)), m2 = stoi(correct.substr(3, 2));

        int diff = (h2 - h1) * 60 + m2 - m1;

        int cnt = diff / 60;
        diff %= 60;

        cnt += diff / 15;
        diff %= 15;

        cnt += diff / 5;
        diff %= 5;
        
        cnt += diff;
        return cnt;
    }
};

int main() {
    Solution sol;
    cout << sol.convertTime("02:30", "03:25");
}