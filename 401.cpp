#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (countBits(h) + countBits(m) == turnedOn) {
                    res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        
        return res;
    }

    int countBits(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<string> res = sol.readBinaryWatch(n);
    for (auto x : res) {
        cout << x << " ";
    }
}