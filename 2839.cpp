#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Lấy các ký tự ở vị trí chẵn và lẻ của s1 và s2
        string even1 = {s1[0], s1[2]};
        string odd1  = {s1[1], s1[3]};
        string even2 = {s2[0], s2[2]};
        string odd2  = {s2[1], s2[3]};
        
        // Sắp xếp lại để kiểm tra khả năng hoán đổi
        sort(even1.begin(), even1.end());
        sort(odd1.begin(), odd1.end());
        sort(even2.begin(), even2.end());
        sort(odd2.begin(), odd2.end());

        // So sánh hai chuỗi con sau khi sắp xếp
        return even1 == even2 && odd1 == odd2;
    }
};