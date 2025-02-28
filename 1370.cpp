#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string result;
        int n = s.size();

        while (result.size() < n) {
            // Bước 1-3: Duyệt từ 'a' -> 'z'
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    result += char(i + 'a');
                    freq[i]--;
                }
            }
            
            // Bước 4-6: Duyệt từ 'z' -> 'a'
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    result += char(i + 'a');
                    freq[i]--;
                }
            }
        }

        return result;
    }
};
