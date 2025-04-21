#include<bits/stdc++.h>

using namespace std;

class Bitset {
private:
    int n;
    vector<int> bitset;
    int countSet;
    bool flipped;

public:
    Bitset(int size) {
        n = size;
        bitset.assign(n, 0);
        countSet = 0;
        flipped = false;        
    }
    
    void fix(int idx) {
        if ((bitset[idx] ^ flipped) == 0) {
            bitset[idx] = flipped ^ 1;
            countSet++;
        }
    }
    
    void unfix(int idx) {
        if ((bitset[idx] ^ flipped) == 1) {
            bitset[idx] = flipped ^ 0;
            countSet--;
        }
    }
    
    void flip() {
        flipped = !flipped;
        countSet = n - countSet;
    }
    
    bool all() {
        return countSet == n;
    }
    
    bool one() {
        return countSet > 0;
    }
    
    int count() {
        return countSet;
    }
    
    string toString() {
        string s;
        for (int i = 0; i < n; i++) {
            s += (bitset[i] ^ flipped) + '0';
        }
        return s;
    }
};


/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */