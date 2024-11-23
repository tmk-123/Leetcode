#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sắp xếp theo thời gian kết thúc
        sort(intervals.begin(), intervals.end(), [] (vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        int prevEnd = intervals[0][1];  

        // greedy Chứng minh bằng phản chứng:
        // Giả sử có một cách khác giữ được nhiều đoạn hơn, nghĩa là nó phải chọn
        // đoạn có thời gian kết thúc lớn hơn một đoạn mà cách này đã chọn. 
        // Nhưng điều đó sẽ khiến các đoạn sau bị chồng chéo nhiều hơn, dẫn đến việc loại bỏ nhiều đoạn hơn -> Mâu thuẫn.
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1];
            }
            else {
                cnt++;
            }
        }

        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> intervals[i][j];
        }
    }

    Solution sol;
    cout << sol.eraseOverlapIntervals(intervals);  
}