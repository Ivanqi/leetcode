#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

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
            // 记录需要跳过的死亡密码
            unordered_set<string> deads (deadends.begin(), deadends.end());
            unordered_set<string> visited;
            queue<string> Q;

            // 从起点开始启动广度优先搜索
            int step = 0;
            Q.push("0000");
            visited.insert("0000");

            while (!Q.empty()) {
                int sz = Q.size();
                // 将当前队列中的所有节点向周围扩散
                for (int i = 0; i < sz; i++) {
                    string cur = Q.front();
                    Q.pop();

                    // 判断是否到达终点
                    if (deads.count(cur)) {
                        continue;
                    }

                    if (cur == target) return step;

                    // 将一个节点的未遍历相邻节点加入队列
                    for (int j = 0; j < 4; j++) {
                        string up = plusOne(cur, j);
                        if (!visited.count(up)) {
                            Q.push(up);
                            visited.insert(up);
                        }

                        string down = minusOne(cur, j);
                        if (!visited.count(down)) {
                            Q.push(down);
                            visited.insert(down);
                        }
                    }
                }
                // 在这里增加步数
                step++;
            }
            // 如果穷举完都没找到目标密码，那就是找不到了
            return -1;
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