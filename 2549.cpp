#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        unordered_set<int> board;
        queue<int> q;

        board.insert(n);
        q.push(n);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            for (int i = 2; i < x; i++) {
                if (x % i == 1 && board.find(i) == board.end()) {
                    board.insert(i);
                    q.push(i);
                }
            }  
        }

        return board.size();
    }
};