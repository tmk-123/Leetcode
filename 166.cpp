#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res;
        // nếu tử và mẫu trái dấu
        if ((numerator < 0) ^ (denominator < 0)) res += "-";

        long long num = abs((long long) numerator);
        long long denom = abs((long long) denominator);
        long long remainder = num % denom;

        res += to_string(num / denom);
        if (remainder == 0) return res;

        res += ".";
        unordered_map<long long, int> mp;

        while (remainder != 0) {
            if (mp.find(remainder) != mp.end()) {
                res.insert(mp[remainder], "(");
                res += ")";
                return res;
            }

            // lưu value của map là vị trí ngoài cùng của res để chèn vào
            mp[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder / denom);
            remainder %= denom;
        }

        return res;
    }
};

int main() {
    int s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    cout << sol.fractionToDecimal(s1, s2);
}       