#include <iostream>
using namespace std;

class TrieNode 
{
    public:
        char data;
        TrieNode *children[26] = {nullptr};
        bool isEndingChar;
        TrieNode(char w) {
            this->data = w;
            this->isEndingChar = false;
        }
};

class Trie {
    public:
        /** Initialize your data structure here. */
        TrieNode *root;
        Trie() {
            root = new TrieNode('/');
        }
        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode *p = root;

            for (int i = 0; i < word.length(); i++) {
                int index = word[i] - 'a';
                if (p->children[index] == NULL) {
                    p->children[index] = new TrieNode(word[i]);
                }
                p = p->children[index];
            }
            p->isEndingChar = true;
        }
        
        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode *p = root;
            for (int i = 0; i < word.length(); i++) {
                int index = word[i] - 'a';
                if (p->children[index] == NULL) return false;
                p = p->children[index];
            }
            return p->isEndingChar;
        }
        
        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode *p = root;
            for (int i = 0; i < prefix.length(); i++) {
                int index = prefix[i] - 'a';
                if (p->children[index] == NULL) return false;
                p = p->children[index];
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
int main() {
    bool ret;
    Trie *trie = new Trie;
    trie->insert("apple");
    ret = trie->search("apple");
    cout << ret << endl;

    ret = trie->search("app");
    cout << ret << endl;

    ret = trie->startsWith("app");
    cout << ret << endl;

    trie->insert("app");   
    ret = trie->search("app");
    cout << ret << endl;
    return 0;   
}