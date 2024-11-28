#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    char c;
    vector<char> s;
    while (cin >> c) {
        s.push_back(c);
    }
    Solution sol;
    sol.reverseString(s);
}