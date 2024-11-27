#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // lớn hơn nghĩa là đã có thể à kết quả
            if (letters[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        if (left >= letters.size()) return letters[0];
        return letters[left];
    }
};

int main() {
    char target;
    cin >> target;
    char n;
    vector<char> letters;
    while (cin >> n) letters.push_back(n);
    Solution sol;
    cout << sol.nextGreatestLetter(letters, target);
}