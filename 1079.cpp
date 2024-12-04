#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (char c : tiles) {
            count[c]++;
        }

        return backtrack(count);
    }

    // quay lui như sau với A : 2, B : 1
    // gốc -> A : total = 1 -> A : total = 1 (AA) -> B : total = 1 (AAB), return 1 quay lui cộng dần total
    //                      -> B : total = 1 (AB) -> A : total = 1 (ABA)
    //   => total tổng của A là (1 + 1) + (1 + 1) + 1 (gốc của A) = 5

    int backtrack(unordered_map<char, int>& count) {
        int total = 0;

        for (auto it : count) {
            char tile = it.first;
            int cnt = it.second;

            if (cnt > 0) {
                total++;
                count[tile]--;
                total += backtrack(count);
                count[tile]++;
            }
        }

        return total;
    }
};

int main() {
    string s;
    cin >> s; 
    Solution sol;
    cout << sol.numTilePossibilities(s);
}