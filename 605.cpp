#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int i = 0;
        while (i < size) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) return true;
            }
            i++;
        } 

        return n <= 0;
    }
};

int main() {
    int n;
    cin >> n;
    int x;
    vector<int> flowerbed;
    while (cin >> x) flowerbed.push_back(x);

    Solution sol;
    cout << sol.canPlaceFlowers(flowerbed, n);
}