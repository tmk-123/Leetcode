#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> Map;
        int bulls = 0, cows = 0;
        string t = guess;

        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                Map[secret[i]]++;
            }
        }

         for (int i = 0; i < secret.length(); i++) {
            if (secret[i] != guess[i] && Map[guess[i]] > 0) {
                cows++;
                Map[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    Solution sol;
    cout << sol.getHint(s1, s2);
}