#include<bits/stdc++.h>

using namespace std;

class OrderedStream {
private:
    vector<string> stream;
    int ptr; // con trỏ chỉ vị trí tiếp theo cần lấy

public:
    OrderedStream(int n) {
        stream.resize(n + 1); // dùng từ chỉ số 1 đến n
        ptr = 1;
    }

    vector<string> insert(int idKey, string value) {
        stream[idKey] = value;
        vector<string> chunk;

        // Trả về các phần tử liên tiếp bắt đầu từ ptr
        while (ptr < stream.size() && !stream[ptr].empty()) {
            chunk.push_back(stream[ptr]);
            ptr++;
        }

        return chunk;
    }
};