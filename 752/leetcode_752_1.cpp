#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 测试用
class Solution {
    public:
        // 将s[j]向上拨动一次
        string plusOne(string s, int j) {
            string ch = s;
            if (ch[j] == '9') {
                ch[j] = '0';
            } else {
                ch[j] = ch[j] + 1;
            }
            return ch;
        }

        // 将s[i]向下波动一次
        string minusOne(string s, int j) {
            string ch = s;
            if (ch[j] == '0') {
                ch[j] = '9';
            } else {
                ch[j] = ch[j] - 1;
            }
            return ch;
        }


        int openLock(vector<string>& deadends, string target) {
            queue<string> Q;
            Q.push("0000");
            int step = 1;
            while (!Q.empty()) {
                int sz = Q.size();
                // 将当前队列中的所有节点向周围扩散
                for (int i = 0; i < sz; i++) {
                    string cur = Q.front();
                    Q.pop();

                    // 判断是否到达终点
                    if (cur == target) {
                        queue<string> empty;
	                    swap(empty, Q);
                        break;
                    };
                    
                    cout << "cur:" << cur << endl;

                    // 将一个节点的相邻节点加入队列
                    for (int j = 0; j < 4; j++) {
                        string up = plusOne(cur, j);
                        string down = minusOne(cur, j);
                        Q.push(up);
                        Q.push(down);
                    }
                }
                step++;
            }

            return step;
        }
};

void test_case_1(Solution So) {
    vector<string> deadends = {
        "0201", "0101", "0102", "1212", "2002"
    };

    string target = "0202";

    int ret = So.openLock(deadends, target);
    cout << "结果为:" << ret << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}