#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hexChars = "0123456789abcdef";
        string res = "";

        // chuyển sang unsigned để mất bit dấu, nếu không nó tính cả bit dấu    
        unsigned int n = num;
        while (n > 0) {
            cout << n << " ";
            // 0x là hệ 16, F = 0000 1111 nên và sẽ ra 4 chữ số cuối
            res = hexChars[n & 0xF] + res;
            n >>= 4;
        }

        return res;
    }
};

int main() {
    Solution sol;
    cout << sol.toHex(-1);
}