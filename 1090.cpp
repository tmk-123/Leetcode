#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v;
        for (int i = 0; i < values.size(); i++) {
            v.push_back({values[i], labels[i]});
        }      
        sort(v.rbegin(), v.rend());

        unordered_map<int, int> m;
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (m[v[i].second] < useLimit) {
                sum += v[i].first;
                m[v[i].second]++;
                numWanted--;
            }  

            if (numWanted == 0) return sum;
        }
        return sum;
    }
};