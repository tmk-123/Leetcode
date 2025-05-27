#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long n = 0;  
        long long sign = (x < 0) ? -1 : 1;
        if (x == INT_MIN) return 0;
        x = abs(x);
        while (x > 0) {
            n = n * 10 + x % 10;
            if (n > INT_MAX) return 0;
            x /= 10;
        }
        return n * sign;      
    }
};
