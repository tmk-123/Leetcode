#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Nếu số lượng ký tự và số lượng từ không bằng nhau, trả về false
        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> map1; // Ánh xạ từ ký tự đến từ
        unordered_map<string, char> map2; // Ánh xạ từ từ đến ký tự

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Kiểm tra ánh xạ của ký tự -> từ
            if (map1.count(c)) {
                if (map1[c] != w) return false;
            } else {
                map1[c] = w;
            }

            // Kiểm tra ánh xạ của từ -> ký tự
            if (map2.count(w)) {
                if (map2[w] != c) return false;
            } else {
                map2[w] = c;
            }
        }

        return true;
    }
};

int main() {
    string p, s;
    cin >> p;
    getline(cin >> ws, s);
    Solution sol;
    cout << sol.wordPattern(p, s);
}