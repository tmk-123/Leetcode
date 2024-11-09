#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int max_area = (r - l) * min(h[l], h[r]);
        while (l < r) {
            if (h[r] < h[l]) r--;
            else l++;
            int area = (r - l) * min(h[l], h[r]);
            max_area = max(area, max_area);
        }

        // bới vì lấy min giữa 2 cái nên nếu h[l] = h[r] thì dịch bên nào cũng như nhau
        return max_area;
    }
};

int main() {
    int n;
    vector<int> num;
    while (cin >> n) {
        num.push_back(n);
    }

    Solution sol;
    cout << sol.maxArea(num);
}