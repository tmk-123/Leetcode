#include<bits/stdc++.h>

using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {
        
    }

    bool book(int startTime, int endTime) {
        for (auto& [s, e] : overlaps) {
            if (max(s, startTime) < min(e, endTime)) return false;
        }
        
        for (auto& [s, e] : booked) {
            int overlapsStart = max(s, startTime);
            int overlapsEnd = min(e, endTime);
            if (overlapsStart < overlapsEnd) overlaps.emplace_back(overlapsStart, overlapsEnd);
        }

        booked.emplace_back(startTime, endTime);
        return true;
    }
};
