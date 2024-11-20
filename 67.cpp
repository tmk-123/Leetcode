#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry){
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            c += carry % 2 + '0'; // số dư = 2 thì c = 0, dư bằng 1;
            carry /= 2;
        }
        
        reverse(c.begin(), c.end());
        return c;
    }
};
int main() {
    string a, b;
    cin >> a >> b;

    Solution sol;
    cout << sol.addBinary(a, b);
}