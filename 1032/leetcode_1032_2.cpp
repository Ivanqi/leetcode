#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trie {
    private:
        bool is_string = false;
        Trie* next[26] = {nullptr};
    public:
        Trie(){}
        void insert(string& word) {
            Trie* root = this;
            for (const auto& w:word) {
                if (root->next[w - 'a'] == nullptr) root->next[w - 'a'] = new Trie();
                root = root->next[w - 'a'];
            }
            root->is_string = true;
        }

        bool startsWith(string& word) {
            Trie* root = this;
            for (int i = word.size() - 1; i >= 0; --i) {
                cout << word[i] << endl;
                if (root->next[word[i] - 'a'] != nullptr) {
                    root = root->next[word[i] - 'a'];
                    if (root->is_string) return true;
                }
                else return false;
            }
            return false;
        }
};

class StreamChecker {
    private:
        Trie* root;
        string word;
    public:
        StreamChecker(vector<string>& words) {
            root = new Trie();
            for (auto word:words) {
                reverse(word.begin(), word.end());
                root->insert(word);
            }
        }

        bool query(char letter) {
            Trie* note = root;
            word.push_back(letter);
            return note->startsWith(word);
        }
};

int main() {
    vector<string> v;
    v.push_back("cd");
    v.push_back("f");
    v.push_back("kl");

    StreamChecker *streamChecker = new StreamChecker(v);

    cout << streamChecker->query('a') << endl;
    cout << streamChecker->query('b') << endl;
    cout << streamChecker->query('c') << endl;
    cout << streamChecker->query('d') << endl;
    cout << streamChecker->query('e') << endl;
    cout << streamChecker->query('f') << endl;
    cout << streamChecker->query('g') << endl;
    cout << streamChecker->query('h') << endl;
    cout << streamChecker->query('i') << endl;
    cout << streamChecker->query('j') << endl;
    cout << streamChecker->query('k') << endl;
    cout << streamChecker->query('l') << endl;
}