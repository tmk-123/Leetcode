#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> m;
        for (int& n : changed) {
            m[n]++;
        }

        vector<int> v;
        for (auto& [n, freq] : m) {
            if (freq > 0) {
                if (n == 0) {
                    if (freq % 2 == 1) return {};
                    freq /= 2;
                    while (freq--) {
                        v.push_back(n);
                    }
                }
                else if (m[2 * n] >= freq) {
                    m[2 * n] -= freq;
                    while (freq--) {
                        v.push_back(n);
                    }
                }
                else return {};
            }
        }
        return v;
    }
};