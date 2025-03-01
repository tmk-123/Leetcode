#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> visited;
        int x = 0, y = 0;
        visited.insert({x, y}); // Lưu vị trí ban đầu

        for (char dir : path) {
            if (dir == 'N') y++;
            else if (dir == 'S') y--;
            else if (dir == 'E') x++;
            else if (dir == 'W') x--;

            if (visited.count({x, y})) return true; // Nếu đã tồn tại
            visited.insert({x, y});
        }

        return false;
    }
};