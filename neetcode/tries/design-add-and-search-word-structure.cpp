#include "leet.h"

struct TrieNode {
    TrieNode* nodes[26];
    bool EOW;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
        EOW = false;
    }
};

class WordDictionary {
public:
    TrieNode* head;
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        addWord(head, word, 0);
    }

    void addWord(TrieNode* curr, string word, int i) {
        if (i > word.size() - 1) {
            curr->EOW = true;
            return;
        }
        if (!curr->nodes[word[i] - 'a']) {
            curr->nodes[word[i] - 'a'] = new TrieNode();
        }
        addWord(curr->nodes[word[i] - 'a'], word, i+1);
    }
    
    bool search(string word) {
        return search(head, word, 0);
    }

    bool search(TrieNode* curr, string word, int i) {
        if (i > word.size() - 1) {
            if (curr->EOW) {
                return true;
            }
            return false;
        }
        bool result = false;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (curr->nodes[j]) {
                    result = result || search(curr->nodes[j], word, i+1);
                }
            }
            return result;
        } else {
            if (!curr->nodes[word[i] - 'a']) {
                return false;
            }
            return search(curr->nodes[word[i] - 'a'], word, i+1);
        }
    }
};
