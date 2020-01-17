#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class StreamChecker {
    public:
        struct TrieNode {
            bool flag;
            TrieNode* next[26] = {nullptr};
            TrieNode(): flag(false){}
        };
        TrieNode* root;
        string s;
        StreamChecker(vector<string>& words) {
            root = new TrieNode();
            for (const auto& w: words) {
                auto node = root;
                for (int i = w.size() - 1; i >= 0; i--) {
                    int k = w[i] - 'a';
                    if (node->next[k] == NULL) {
                        node->next[k] = new TrieNode();
                    }
                    node = node->next[k];
                }
                node->flag = true;
            }
        }

        bool query(char letter) {
            s += letter;
            auto node = root;
            for (int i = s.size() - 1; i >= 0; --i) {
                int k = s[i] - 'a';
                if (node->next[k] != NULL) {
                    node = node->next[k];
                    if (node->flag) return true;
                } else {
                    return false;
                }
            }
            return false;
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