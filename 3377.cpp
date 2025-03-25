#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int minOperations(int n, int m) {
        if (isPrime(n) || isPrime(m)) return -1;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // {so hien tai, tong chi phi}
        unordered_set<int> visited;
        visited.insert(n);
        pq.push({n, n});

        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();         

            if (cur == m) return cost;

            string s = to_string(cur);
            for (int i = 0; i < s.size(); i++) {
                for (int d : {-1, 1}) {
                    if ((s[i] == '0' && d == -1) || (s[i] == '9' && d == 1)) continue;

                    string t = s;
                    t[i] += d;

                    int nextNum = stoi(t);
                    if (!visited.count(nextNum) && !isPrime(nextNum)) {
                        visited.insert(nextNum);
                        pq.push({cost + nextNum, nextNum});
                    }
                }
            }
        }

        return -1;
    }
};