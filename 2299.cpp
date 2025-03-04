#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.length() < 8) return false;
        
        bool hasLowercase = false, hasUppercase = false;
        bool hasDigit = false, hasSpecialChar = false; 
        string specialStr = "!@#$%^&*()-+";
        for (int i = 0; i < password.length(); i++) {
            char c = password[i];
            if ('A' <= c && c <= 'Z') hasUppercase = true;
            if ('a' <= c && c <= 'z') hasLowercase = true;
            if (isdigit(c)) hasDigit = true;
            if (specialStr.find(c) != string::npos) hasSpecialChar = true;  
            if (i > 0 && password[i] == password[i - 1]) return false;    
        }

        if (!hasLowercase || !hasUppercase || !hasDigit || !hasSpecialChar) return false;
        return true;
    }
};