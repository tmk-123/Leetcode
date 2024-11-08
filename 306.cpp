#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string n) {
        if (n.length() < 3) return 0;
    
        for (int i = 1; i < n.length(); i++) {
            for (int j = 1; i + j + j <= n.length(); j++) {
                if (check(n, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool check(string n, int begin, int len1, int len2) {
        string s1 = n.substr(begin, len1);
        string s2 = n.substr(begin + len1, len2);
        if ((s1.length() > 1 && s1[0] == '0') || (s2.length() > 1 && s2[0] == '0')) return false;

        string s3 = sum_string(s1, s2);
        if (s3.length() > n.length() - len1 - len2 - begin) return false;

        if (s3 == n.substr(begin + len1 + len2, s3.length())) {
            if (s3.length() + len1 + len2 + begin == n.length()) return true;
            return check(n, begin + len1, len2, s3.length());
        }
        return false;
    }

    string sum_string(string s1, string s2) {
        if (s1.length() > s2.length()) swap(s1, s2);
        while (s1.length() < s2.length()) s1.insert(0, "0");
        
        int memory = 0;
        string s;
        for (int i = s1.length() - 1; i >= 0; i--) {
            int sum = (s1[i] - '0') + (s2[i] - '0') + memory;
            s.push_back(sum % 10 + '0');
            memory = sum / 10;
        }

        if (memory) s.push_back(memory + '0');
        reverse(s.begin(), s.end());  
        return s;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isAdditiveNumber(s);
}