#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

/**
 * 时间复杂度: O(time),
 * 空间复杂度: O(n)
 */

/**
 * 贪心思维，总是处理，频率最高的任务
 */
class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            // 定义一个记录每个任务频率的数组
            int count[26];
            // 把记录频率的数组初始化为0，这行代码很关键，不加会报错
            memset(count, 0, sizeof(count));
            // 统计每个任务出现的频率
            for (int i = 0; i < tasks.size(); i++) {
                // 用 26个大写英文字母的ASII 减去 A 的ACII，保证数组下表从0开始
                count[tasks[i] - 'A']++;
            }

            // 把任务频率升序排列 count[25] 为频率最高任务
            sort(count, count + 26);

            int time = 0;
            while (count[25] > 0) {
                int i = 0;
                while (i <= n) {
                    if (count[25] == 0) {
                        break;
                    }
                    // cout << "i : " << i << " : " << count[25 - i] << endl;
                    if (i < 26 && count[25 - i] > 0) {
                        count[25 - i]--;
                    }
                    time++;
                    i++;
                }
                sort(count, count + 26);
            }
           
           return time;
        }
};

void test_leastInterval_1(Solution So) {
    vector<char> v;
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('B');
    v.push_back('B');
    v.push_back('B');
    cout << "size: " << So.leastInterval(v, 2) << endl;
}

void test_leastInterval_2(Solution So) {
    vector<char> v;
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('B');
    v.push_back('B');
    v.push_back('B');
    cout << "size: " << So.leastInterval(v, 0) << endl;
}

int main() {
    Solution So;
    test_leastInterval_1(So);
}