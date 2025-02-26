#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int x = n ^ (n >> 1); // nếu n có dạng 101010... thì sẽ full 1;
        if (x == INT_MAX) return true; 
        return (x & (x + 1)) == 0;
    }
};

int main() {
    Solution sol;
    cout << sol.hasAlternatingBits(4);
}