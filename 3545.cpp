#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> m;
        for (char& c : s) m[c]++;
        if (m.size() <= k) return 0;
        
        vector<pair<int, int>> v;
        for (auto [c, f] : m) {
            v.push_back({c, f});  
        }
        sort(v.begin(), v.end(), compare);
        
        int n = m.size();
        int i = 0;
        int cnt = 0;
        while (n > k) {
            cnt += v[i].second;
            i++;
            n--;
        }
        return cnt;
    }
};