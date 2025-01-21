int minSubarraySum(vector<int>& nums, int l, int r) {
    int n = nums.size();
    int minSum = INT_MAX; // Biến lưu tổng nhỏ nhất
    int currentSum = 0;   // Biến lưu tổng của cửa sổ hiện tại
    int windowSize = 0;   // Kích thước cửa sổ

    int left = 0; // Con trỏ trái
    for (int right = 0; right < n; ++right) {
        // Mở rộng cửa sổ
        currentSum += nums[right];
        windowSize++;

        // Nếu cửa sổ lớn hơn kích thước tối đa, thu hẹp lại
        while (windowSize > r) {
            currentSum -= nums[left];
            left++;
            windowSize--;
        }

        // Nếu cửa sổ đạt kích thước hợp lệ, kiểm tra điều kiện
        if (windowSize >= l && currentSum > 0) {
            minSum = min(minSum, currentSum);
        }
    }

    // Nếu không tìm được subarray thoả mãn, trả về -1
    return (minSum == INT_MAX) ? -1 : minSum;
}
