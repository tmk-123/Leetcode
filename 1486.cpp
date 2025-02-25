#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        start ^= (1 << (n - 2));
        return start;
    }
};  

int main() {
    Solution sol;
    cout << sol.xorOperation(4, 3);
}