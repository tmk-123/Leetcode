#include<bits/stdc++.h>

using namespace std;

bool compare(const string &a, const string &b) {
    string s1 = a + b;
    string s2 = b + a;
    return s1 > s2;
}

class Solution {
public: 
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto x : nums) {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), compare);

        string res;
        for (auto x : v) {
            res += x;
        }
        
        if (res[0] == '0') return "0";
        return res;
    }
};

int main() {
    int n;
    vector<int> num;
    while (cin >> n) {
        num.push_back(n);
    }

    Solution sol;
    cout << sol.largestNumber(num);
}