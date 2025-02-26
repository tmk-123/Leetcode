#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1); // Dịch trái result và lấy bit cuối của n
            n >>= 1; // Dịch phải n để xét bit tiếp theo
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseBits(00000010100101000001111010011100);
}