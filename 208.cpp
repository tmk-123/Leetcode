#include<bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto& a : child) a = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (auto& ch : word) {
            int i = ch - 'a';
            if (!node->child[i]) node->child[i] = new TrieNode();
            node = node->child[i];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for (auto& ch : word) {
            int i = ch - 'a';
            if (!node->child[i]) return false;
            node = node->child[i];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto& ch : prefix) {
            int i = ch - 'a';
            if (!node->child[i]) return false;
            node = node->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */