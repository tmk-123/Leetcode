#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // dùng un_ordermap mà không cần sắp xếp chỉ tốn O(1), map là O(log n), còn s.find là O(n)
        unordered_map<string, int> Map;
        if (s.length() <= 10) return {};

        for (int i = 0; i <= s.length() - 10; i++) {
            string t = s.substr(i, 10);
            Map[t]++;
        }

        vector<string> res;
        for (auto x : Map) {
            if (x.second > 1) res.push_back(x.first);
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    vector<string> v = sol.findRepeatedDnaSequences(s);
    for (string x : v) {
        cout << x << " ";
    }
}