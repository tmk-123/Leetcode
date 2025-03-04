#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;  // Hai chuỗi giống nhau => Không có LUS
        return max(a.length(), b.length());  // Chuỗi dài hơn là LUS
    }
};
