#include<bits/stdc++.h>

using namespace std;

// Min-heap
struct comparator {
    // dấu () là toán tử gọi hàm
    bool operator()(string& a, string& b) {

        // return true thì a có độ ưu tiên thấp hơn(ngược)
        if (a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comparator> minHeap;
        
        for (string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        } 

        return minHeap.top();
    }
};