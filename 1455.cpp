#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        
        int cnt = 1;
        while (ss >> word){ 
            if (word.find(searchWord) != string::npos && word.find(searchWord) == 0) {
                return cnt;
            }
            cnt++;
        }

        return -1;
    }
};

int main() {
    string sentence, searchWord;
    getline(cin, sentence);
    cin >> searchWord;

    Solution sol;
    cout << sol.isPrefixOfWord(sentence, searchWord);
}