#include<bits/stdc++.h>

using namespace std;

// vì phải tìm tất cả các phương án và tìm các từ khác nhau 1 ký tự tức khác nhau 1 level nên dùng BFS
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> res;

        if (!wordSet.count(endWord)) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currentLevel{beginWord};
        unordered_set<string> nextLevel;
        bool found = false;

        // duyệt mọi cấp độ để tìm mọi parents của từ, sau đó dùng backtrack từ cuối lên để tìm path
        while (!currentLevel.empty() && !found) {
            // xóa các từ ở level hiện tại đê tránh quay lại
            for (string word : currentLevel) {
                wordSet.erase(word);
            }

            // xét mỗi từ ở level hiện tại
            for (string word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    // xét từng chữ cái, nếu được thì push vào parent của word thêm temp
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (wordSet.count(temp)) {
                            parents[temp].push_back(word);
                            nextLevel.insert(temp);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original; // khôi phục để chuyển sang ký tự khác của temp 
                }
            }
            currentLevel = nextLevel;
            nextLevel.clear();
        }
        if (found) {
            vector<string> path{endWord};
            backtrack(endWord, beginWord, parents, path, res);
        }

        return res;
    }

    void backtrack(string& word, string& beginWord, unordered_map<string, vector<string>>& parents, vector<string>& path, vector<vector<string>> &res) {
        if (word == beginWord) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        for (string parent : parents[word]) {
            path.push_back(parent);
            backtrack(parent, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};

int main() {
    string beginWord, endWord, s;
    cin >> beginWord >> endWord;
    vector<string> wordList;
    while (cin >> s) {
        wordList.push_back(s);
    }

    Solution sol;
    vector<vector<string>> res = sol.findLadders(beginWord, endWord, wordList);
    for (auto x : res) {
        for (auto str : x) {
            cout << str << " ";
        }
        cout << endl;
    }
}