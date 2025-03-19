#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long countPairs;

    void countValidPairs(vector<int>& values, int left, int mid, int right, int diff) {
        int l = left, r = mid + 1;
        
        while (l <= mid && r <= right) {
            if (values[l] <= values[r] + diff) {  
                countPairs += (right - r + 1);  // Các phần tử từ r đến right đều thỏa mãn
                l++;
            }
            else r++;
        }

        // Sắp xếp đoạn từ left đến right để duy trì tính chất của merge sort
        sort(values.begin() + left, values.begin() + right + 1);
    }

    void mergeSort(vector<int>& values, int left, int right, int diff) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(values, left, mid, diff);
        mergeSort(values, mid + 1, right, diff);
        
        countValidPairs(values, left, mid, right, diff);
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> values(n);
        
        for (int i = 0; i < n; i++) {
            values[i] = nums1[i] - nums2[i];
        }

        countPairs = 0;
        mergeSort(values, 0, n - 1, diff);

        return countPairs;
    }
};