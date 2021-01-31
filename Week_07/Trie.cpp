class Trie {
    struct TrieNode {
        map<char, TrieNode*> childTable;
        int isEnd;
        TrieNode(): isEnd(0) {}
    };
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (cur->childTable.count(word[i]) == 0) {
                cur->childTable[word[i]] = new TrieNode();
            }
            cur = cur->childTable[word[i]];
        }
        cur->isEnd = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
    private: 
    TrieNode* root;
    bool find(string s, int allMatch) {
        TrieNode* cur = root;
        for (int i = 0; i < s.length(); ++i) {
            if (cur->childTable.count(s[i]) == 0) {
                return false;
            }
            cur = cur->childTable[s[i]];
        }
        if (allMatch) {
            return cur->isEnd == 1;
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
