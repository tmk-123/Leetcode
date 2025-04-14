#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void shiftLeft(vector<int>& v, int index) {
        for (int i = index; i < v.size() - 1; i++) {
            v[i] = v[i + 1];
        }
        v.pop_back();
    }

    void merge(vector<int>& v) {
        int minSum = INT_MAX;
        int minIdx = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            int sum = v[i] + v[i + 1];
            if (sum < minSum) {
                minIdx = i;
                minSum = sum;
            }
        }
        v[minIdx] = minSum;
        shiftLeft(v, minIdx + 1);
    }

    bool isSorted(vector<int>& v) {
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!isSorted(nums)) {
            merge(nums);
            cnt++;
        }
        return cnt;
    }
};