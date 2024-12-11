#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (1) {
            int n = 0;
            while (num > 0) {
                n += num % 10;
                num /= 10;
            }
            if (n < 10) return n;
            else num = n;
        }   
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.addDigits(n);    
}