#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long t) {
        int n = num.length();

        // lưu khả năng chia hết tại mỗi vị trí, chia dần từ trái sang phải
        // cho ucln với chữ số đó, nêu đến cuối mà = 1 thì nó chia hết cho t
        vector<long> divisibility(n + 1);
        divisibility[0] = t;
        int firstZeroIndex = n;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZeroIndex = i + 1;
                break;
            }
            divisibility[i + 1] = divisibility[i] / gcd(divisibility[i], num[i] - '0');
        }
        
        // nếu không cần gì thay đổi, tức số đó đã chia hết cho t rồi, return
        if (firstZeroIndex == n && divisibility[n] == 1) return num;

        // duyệt ngược từ vị trí đầu tiên số 0 xuất hiện, bởi ta phải loại số 0
        for (int i = firstZeroIndex - 1; i >= 0; i--) {
            while (num[i] < '9') {
                long tempT = divisibility[i];
                num[i]++;
                tempT /= gcd(tempT, num[i] - '0');
                
                // thử thay thế các số phía sau bằng số nhỏ nhất có thể
                for (int j = n - 1; j > i; j--) {
                    // duyệt từ cuối bởi chữ số càng bên phải to thì số đấy càng nhỏ, đỡ phải sang trái
                    for (int k = 9; k > 0; k--) {
                        if (tempT % k == 0) {
                            tempT /= k;
                            num[j] = '0' + k;
                            break;
                        }
                    }
                }

                if (tempT == 1) return num;
            }
        }

        // nếu duyệt hết bên trên mà chưa tìm thấy thì số cần tìm to hơn mà chưa duyệt tới, có thể nhiều chữ số hơn
        string res;
        for (int i = 9; t > 1 && i > 1; i--) {
            while (t % i == 0) {
                res += to_string(i);
                t /= i;
            } 
        }

        if (t != 1) return "-1";

        reverse(res.begin(), res.end());

        // nếu res > num
        if (isGreaterThan(res, num)) return res;
        
        // nếu res <= num thì thêm 1 vào 
        int lenDif = num.length() - res.length();
        if (isGreaterThan(string(lenDif, '1') + res, num)) return string(lenDif, '1') + res;    

        // nếu thêm 1 vẫn chưa lớn hơn thì thêm 1 một lần nữa
        return string(lenDif + 1, '1') + res;
    }

    long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    bool isGreaterThan(string a, string b) {
        if (a.length() == b.length()) return a > b;
        return a.length() > b.length();
    }
};

int main() {
    string num;
    long long t;
    cin >> num >> t;
    Solution sol;
    cout << sol.smallestNumber(num, t);
}