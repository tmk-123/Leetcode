#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitmasks(n, 0); // bitmasks for every word
        vector<int> lengths(n, 0);

        for (int i = 0; i < n; i++) {
            int bitmask = 0;
            for (char c : words[i]) {
                // a là 2^0, b là 2^1, .... xong đó lưu cả từ vào bitmasks
                bitmask |= (1 << (c - 'a')); 
            }
            bitmasks[i] = bitmask;
            lengths[i] = words[i].size();
        }

        int maxProduct = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // nếu cả 2 khi AND = 0 tức là không có chữ cái nào bằng nhau
                if ((bitmasks[i] & bitmasks[j]) == 0) {
                    maxProduct = max(maxProduct, lengths[i] * lengths[j]);
                }
            }
        }

        return maxProduct;
    }
};


int main() {
    vector<string> words;
    string s;
    while (cin >> s) {
        words.push_back(s);
    }

    Solution sol;
    cout << sol.maxProduct(words);
}