#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }

        map<int, vector<string>> m1;
        for (int i = 0; i < list2.size(); i++) {
            if (m.find(list2[i]) != m.end()) {
                m1[i + m[list2[i]]].push_back(list2[i]);
            }
        }
        for (auto x : m1) {
            return x.second;
        }
        return {};
    }
};