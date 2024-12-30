#include<bits/stdc++.h>

using namespace std;

class BrowserHistory {
private:
    vector<string> history;
    int currentIndex;
    int lastValidIndex;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIndex = 0;
        lastValidIndex = 0;
    }
    
    void visit(string url) {
        if (currentIndex + 1 < history.size()) {
            history[currentIndex + 1] = url;
        }
        else history.push_back(url);
        currentIndex++;
        lastValidIndex = currentIndex;
    }
    
    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return history[currentIndex];
    }
    
    string forward(int steps) {
        currentIndex = min(lastValidIndex, currentIndex + steps);
        return history[currentIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */