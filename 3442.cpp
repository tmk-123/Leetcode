#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        
        // Bước 1: Đếm tần suất xuất hiện của mỗi ký tự
        for (char c : s) {
            freq[c]++;
        }

        vector<int> odd_freqs, even_freqs;

        // Bước 2: Phân loại tần suất chẵn & lẻ
        for (auto &[ch, count] : freq) {
            if (count % 2 == 0) even_freqs.push_back(count);
            else odd_freqs.push_back(count);
        }

        // Bước 3: Tìm max(odd) và min(even)
        int max_odd = *max_element(odd_freqs.begin(), odd_freqs.end());
        int min_even = *min_element(even_freqs.begin(), even_freqs.end());

        return max_odd - min_even;
    }

};