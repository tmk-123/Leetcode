#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int k) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;

        priority_queue<pair<char, int>> pq;
        for (auto& [c, freq] : m) {
            pq.emplace(c, freq);
        }

        string res;
        while (!pq.empty()) {
            auto [ch, count] = pq.top(); pq.pop();
            int used = min(k, count);
            res += string(used, ch);
            count -= used;

            if (count > 0) {
                if (pq.empty()) break;
                auto [nextCh, nextCount] = pq.top(); pq.pop();
                res += nextCh;
                nextCount--;

                if (nextCount > 0) pq.emplace(nextCh, nextCount);
                pq.emplace(ch, count);
            }
        }

        return res;
    }
};