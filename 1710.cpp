#include<bits/stdc++.h>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) return a[0] > b[0];
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int sum = 0;
        for (int i = 0; i < boxTypes.size(); i++) {
            if (boxTypes[i][0] <= truckSize) {
                sum += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else {
                sum += truckSize * boxTypes[i][1];
                return sum;
            }
        }
        return -1;
    }
};