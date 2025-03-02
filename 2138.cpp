#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> divideString(const string &s, int k, char fill) {
        vector<string> result;
        int n = s.length();

        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);
            if (group.length() < k) {
                group.append(k - group.length(), fill); // Thêm ký tự fill nếu nhóm cuối chưa đủ k ký tự
            }
            result.push_back(group);
        }

        return result;
    }
};