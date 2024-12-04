#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();
        for (int i = 1; i <= 10 && i < n; ++i) {
            if (i > 1 && num[0] == '0') break;  // Số bắt đầu bằng '0' không hợp lệ
            long long a = stoll(num.substr(0, i));
            if (a > INT_MAX) break;

            for (int j = 1; j <= 10 && i + j < n; ++j) {
                if (j > 1 && num[i] == '0') break;  // Số bắt đầu bằng '0' không hợp lệ
                long long b = stoll(num.substr(i, j));
                if (b > INT_MAX) break;

                vector<int> res = {(int)a, (int)b};
                if (isValid(i + j, a, b, num, res)) return res;
            }
        }
        return {};
    }

private:
    bool isValid(int start, long long a, long long b, string& num, vector<int>& res) {
        // start là từ ký tự đầu tiên của c
        while (start < num.length()) {
            long long c = a + b;
            if (c > INT_MAX) return false;

            string sum = to_string(c);
            if (sum != num.substr(start, sum.length())) return false;
            res.push_back((int)c);

            start += sum.length();
            a = b;
            b = c;
        }
        
        return true;
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