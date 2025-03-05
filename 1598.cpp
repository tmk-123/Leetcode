#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;

        for (string log : logs) {
            if (log == "../") {
                if (depth > 0) depth--;  // Chỉ lùi lại nếu không ở thư mục chính
            } else if (log != "./") {
                depth++;  // Đi vào thư mục con
            }
        }

        return depth;
    }
};