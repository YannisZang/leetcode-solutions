#include <string>

// 208. Implement Trie (Prefix Tree)

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

    void freeTrie(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->child[i])
                freeTrie(node->child[i]);
        }
        delete node; // 最后释放当前节点
    }
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        freeTrie(root);
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