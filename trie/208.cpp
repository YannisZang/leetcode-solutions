#include <string>

using namespace std;


class TrieNode {
    public:
        TrieNode* child[26];
        bool isEnd;

    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
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
        for (char& c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            int idx = c - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char& c : prefix) {
            int idx = c - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
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