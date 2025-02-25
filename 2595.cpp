#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0, index = 0;
    
        while (n > 0) {
            if (n & 1) {  // Kiểm tra bit thấp nhất có phải 1 không
                if (index % 2 == 0) even++;  // Vị trí chẵn
                else odd++;  // Vị trí lẻ
            }
            n >>= 1;  // Dịch phải để kiểm tra bit tiếp theo
            index++;  
        }
        
        return {even, odd};
    }
};