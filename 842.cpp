#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        for (int i = 1; i < num.length() && i < 11; i++) {
            for (int j = 1; j + i < num.length() && j < 11; j++) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j); 

                if ((i > 1 && s1[0] == '0') || (j > 1 && s2[0] == '0')) continue;
                if (stoll(s1) > INT_MAX || stoll(s2) > INT_MAX) continue;

                vector<int> res;
                res.push_back(stoll(s1));
                res.push_back(stoll(s2));

                if (backtrack(0, s1, s2, num, res)) return res;
            }
        }

        return {};
    }

    bool backtrack(int begin, string s1, string s2, string num, vector<int>& res) {
        string s3 = sum_string(s1, s2);
        if ((s3.length() + begin + s1.length() + s2.length() > num.length()) || (s3.length() > 1 && s3[0] == '0') || stoll(s3) > INT_MAX) return false;
        
        res.push_back(stoll(s3));

        if (s3 == num.substr(begin + s1.length() + s2.length(), s3.length())) {
            if (begin + s1.length() + s2.length() + s3.length() == num.length()) return true;
            return backtrack(begin + s1.length(), s2, s3, num, res);
        }

        return false;
    }

    string sum_string(string s1, string s2) {
        if (s1.length() < s2.length() || (s1.length() == s2.length() && s1 < s2)) swap(s1, s2);
        while (s1.length() > s2.length()) s2.insert(0, "0");

        string sum = "";
        int remainder = 0;
        for (int i = s1.length() - 1; i >= 0; i--) {
            int x = (s1[i] - '0') + (s2[i] - '0') + remainder;
            sum.push_back((x % 10) + '0');
            remainder = x / 10;
        }

        if (remainder) sum.push_back(remainder + '0');
        reverse(sum.begin(), sum.end());

        return sum;
    }
};

int main() {
    string num;
    cin >> num;
    Solution sol;
    vector<int> res = sol.splitIntoFibonacci(num);
    for (int x : res) {
        cout << x << " ";
    }
}