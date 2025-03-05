#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
   string interpret(string command) {
        string result;
        for (size_t i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    result += 'o';
                    i++;  // Bỏ qua ký tự ')'
                } else {
                    result += "al";
                    i += 3;  // Bỏ qua "al)"
                }
            }
        }
        return result;
    }
};