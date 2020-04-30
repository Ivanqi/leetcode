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
            unordered_set<string> q1;
            unordered_set<string> q2;

            // 从起点开始启动广度优先搜索
            int step = 0;
            q1.insert("0000");
            q2.insert(target);

            while (!q1.empty() && !q2.empty()) {
                // 哈希集合在遍历的过程中不能修改，用temp存储扩散结果
                unordered_set<string> temp;

                // 将q1中的所有节点向周围扩散
                for (auto cur = q1.begin(); cur != q1.end(); ++cur) {
                    // 判断是否达到终点
                    if (deads.count(*cur)) continue;
                    if (q2.count(*cur)) return step;

                    visited.insert(*cur);

                    // 将一个节点的未遍历相邻节点加入集合
                    for (int j = 0; j < 4; j++) {
                        string up = plusOne(*cur, j);
                        if (!visited.count(up)) {
                            temp.insert(up);
                        }

                        string down = minusOne(*cur, j);
                        if (!visited.count(down)) {
                            temp.insert(down);
                        }
                    }
                }
                step++;
                // temp 相当于 q1
                // 这里交换 q1, q2，下一轮while就扩散q2
                q1 = q2;
                q2 = temp;
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