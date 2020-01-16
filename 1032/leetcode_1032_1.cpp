#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class AcNode
{
    public:
        char data;
        AcNode *children[26] = {nullptr};       // 字符集只包含a ~ z这26个字符
        bool isEndingChar;                      // 结尾字符为true
        int length;                             // 当isEndingChar = true时候，记录模式串长度
        AcNode *fail;                           // 失败指针
        AcNode(char w) {
            this->data = w;
            this->isEndingChar = false;
            this->length = -1;
        }
};

class StreamChecker {
    private:
        void buildFailurePointer() {
            queue<AcNode*> Q;
            root->fail = NULL;
            Q.push(root);
            
            while (!Q.empty()) {
                AcNode *p = Q.front();
                Q.pop();

                for (int i = 0 ; i < 26; i++) {
                    AcNode *pc = p->children[i];
                    if (pc == NULL) continue;
                    if (p == root) {
                        p->fail = root;
                    } else {
                        AcNode *q = p->fail;
                        while (q != NULL) {
                            AcNode *qc = q->children[p->data - 'a'];
                            if (qc != NULL) {
                                pc->fail = qc;
                                break;
                            }
                            q = q->fail;
                        }
                        if (q == NULL) pc->fail = root;
                    }
                    Q.push(pc);
                }
            }
        }

        void insert(string word) {
            AcNode *p = root;

            for (int i = 0; i < word.length(); i++) {
                int index = word[i] - 'a';
                if (p->children[index] == NULL) {
                    p->children[index] = new AcNode(word[i]);
                }
                p = p->children[index];
            }
            p->isEndingChar = true;
            p->length = word.length();
        }
    public:
        AcNode *root;
        string s;
        StreamChecker(vector<string>& words) {
            root = new AcNode('/');
            for (int i = 0; i < words.size(); i++) {
                this->insert(words[i]);
            }
        }
        
        bool query(char letter) {
            AcNode *p = root;
            s += letter;
            for (int i = 0; i < s.size(); ++i) {
                int idx = s[i] - 'a';
                cout << s[i] << ':' << idx << endl;
                while (p != NULL && p != root && p->children[idx] == NULL) {
                    p = p->fail;                            // 失败指针发挥作用的地方
                }

                if (p != NULL) {
                    p = p->children[idx];
                }

                AcNode *tmp = p;
                while (tmp != NULL && tmp != root) {       // 打印出可以匹配的模式串
                    if (tmp->isEndingChar == true) {
                        return true;
                    }
                    tmp = tmp->fail;
                }
            }
            return false;
        }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
    vector<string> v;
    v.push_back("cd");
    v.push_back("f");
    v.push_back("kl");

    StreamChecker *streamChecker = new StreamChecker(v);

    cout << streamChecker->query('a') << endl;
    cout << "----" << endl;
    cout << streamChecker->query('b') << endl;
    cout << "----" << endl;
    cout << streamChecker->query('c') << endl;
    cout << "----" << endl;
    cout << streamChecker->query('d') << endl;
    cout << "----" << endl;
    // cout << streamChecker->query('e') << endl;
    // cout << streamChecker->query('f') << endl;
    // cout << streamChecker->query('g') << endl;
    // cout << streamChecker->query('h') << endl;
    // cout << streamChecker->query('i') << endl;
    // cout << streamChecker->query('j') << endl;
    // cout << streamChecker->query('k') << endl;
    // cout << streamChecker->query('l') << endl;
}