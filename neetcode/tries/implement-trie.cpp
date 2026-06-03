#include "leet.h"

struct Node {
    Node* nodes[26];
    bool endOfString;
    Node() {
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
        endOfString = false;
    }
};
class PrefixTree {
public:
    Node* tree;
    PrefixTree() {
        tree = new Node();
    }
    
    void insert(string word) {
        Node* curr = tree;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->nodes[word[i] - 'a']) {
                curr->nodes[word[i] - 'a'] = new Node();
            }
            curr = curr->nodes[word[i] - 'a'];
        }
        curr->endOfString = true;
    }
    
    bool search(string word) {
        Node* curr = tree;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->nodes[word[i] - 'a']) {
                return false;
            }
            curr = curr->nodes[word[i] - 'a'];
        }
        if (!curr->endOfString) {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = tree;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->nodes[prefix[i] - 'a']) {
                return false;
            }
            curr = curr->nodes[prefix[i] - 'a'];
        }
        return true;
    }
};
