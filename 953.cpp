#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> order_map;
        
        for (int i = 0; i < order.size(); i++) {
            order_map[order[i]] = i;
        }
        
        // Bước 2: So sánh từng cặp từ liên tiếp
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            
            int len1 = word1.size();
            int len2 = word2.size();
            bool valid = false;

            // So sánh từng ký tự trong hai từ
            for (int j = 0; j < min(len1, len2); j++) {
                if (order_map[word1[j]] < order_map[word2[j]]) {
                    valid = true;
                    break;
                } else if (order_map[word1[j]] > order_map[word2[j]]) {
                    return false;
                }
            }
            
            // Nếu hai từ giống nhau ở phần đầu nhưng từ đầu dài hơn
            if (!valid && len1 > len2) return false;
        }
        
        return true;
    }
};