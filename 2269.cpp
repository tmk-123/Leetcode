#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt = 0;
        string s = to_string(num);

        for (int i = 0; i <= s.length() - k; i++) {
            string t = s.substr(i, k);
            int n = stoi(t);

            if (n && num % n == 0) cnt++;
        }

        return cnt;
    }
};
int main() {
    Solution sol;
    cout << sol.divisorSubstrings(240, 2);
}