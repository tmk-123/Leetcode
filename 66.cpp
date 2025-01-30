#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int memory = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9 && memory == 1) digits[i] = 0;
            else if (digits[i] != 9 && memory == 1) {
                digits[i]++;
                memory = 0;
            }
        }

        if (memory) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    vector<int> v = {9, 9};
    Solution sol;
    vector<int> res = sol.plusOne(v);
    for (int x : res) {
        cout << x << " ";
    }
}