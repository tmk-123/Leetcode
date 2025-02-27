#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // cho mask vượt quá. vd 101 -> 1000 sau đó trừ 1 thành 0111
        unsigned int mask = 1;
        while (mask <= num) {
            mask = (mask << 1);
        }

        return (mask - 1) ^ num;
    }
};

int main() {
    Solution sol;
    cout << sol.findComplement(5);
}