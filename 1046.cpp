class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Tạo max-heap bằng cách dùng priority_queue
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // Lặp lại cho đến khi còn 1 hoặc không còn viên đá nào
        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop(); // Lấy viên lớn nhất
            int stone2 = maxHeap.top(); maxHeap.pop(); // Lấy viên lớn thứ hai

            // Nếu hai viên không bằng nhau, đưa phần dư trở lại heap
            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }

        // Nếu còn một viên, trả về khối lượng của nó, nếu không thì trả về 0
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};