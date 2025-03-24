#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // dùng bellman ford vì có chu trình dương, ko dùng dijkstra
    void bellman(unordered_map<string, double>& best, vector<vector<string>>& pair, vector<double>& rates) {
        for (int relax = 0; relax < pair.size(); relax++) {
            for (int i = 0; i < pair.size(); i++) {
                best[pair[i][1]] = max(best[pair[i][1]], best[pair[i][0]] * rates[i]);
                best[pair[i][0]] = max(best[pair[i][0]], best[pair[i][1]] / rates[i]);
            }
        }
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, double> best;
        best[initialCurrency] = 1;
        bellman(best, pairs1, rates1);
        bellman(best, pairs2, rates2);
        return best[initialCurrency];
    }
};