#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int cnt = 0; // số cái cần hoán đổi
        for (char c : s) {
            if (c == '[') {
                balance++;
            }
            else {
                balance--;
                if (balance < 0) {
                    cnt = max(cnt, -balance);
                }
            }
        }

        // vì mỗi lần hoán đổi giúp mất đi 2 cái
        return (cnt + 1) / 2;
    }
};