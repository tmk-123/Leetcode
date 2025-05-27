#include<bits/stdc++.h>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), compare);
        int maxDefenseSoFar = 0;
        int weakCount = 0;

        // vì thằng có attack lớn nhất thì chắc chắn không thể yếu vì ko ai qua chỉ số attack của nó
        // và những thằng tiếp theo phải xem thằng có attack lớn hơn, trong số đó ai có defense lớn hơn không
        // nếu attack bằng nhau thì xếp theo defense tăng dần vì nếu xếp giảm dần thì thằng có defense nhỏ hơn
        // sẽ được tính là yếu dù attack bằng nhau
        for (auto& p : properties) {
            if (p[1] < maxDefenseSoFar) {
                weakCount++; // yếu
            } else {
                maxDefenseSoFar = p[1]; // cập nhật max phòng thủ
            }
        }

        return weakCount;
    }
};