#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (int x : arr1) {
            m[x]++;
        }

        vector<int> res;
        for (int i = 0; i < arr2.size(); i++) {
            if (m.find(arr2[i]) != m.end()) {
                while (m[arr2[i]]--) {
                    res.push_back(arr2[i]);
                }
            }
        }

        for (auto x : m) {
            if (x.second > 0) {
                while (x.second--) {
                    res.push_back(x.first);
                }
            }
        }

        return res;
    }
};

