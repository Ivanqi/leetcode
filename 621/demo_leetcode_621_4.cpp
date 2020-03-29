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
 * 时间复杂度: O(M), 其中M是任务总数
 * 空间复杂度: O(1)
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

            /**
             * 在将所有的任务安排完成后，如果仍然有剩余的空闲空间，那么答案即为(任务总数 + 剩余的空闲时间)
             * 如果在安排某一个任务时，遇到了剩余的空间不足的情况，那么答案一定就等于任务的总数
             * 这是因为我们可以将空闲时间增加虚拟的一列，继续安排安排任务
             * 如果不考虑这些虚拟的列，在原本空闲时间对应的那些列中的任务是可以按照要求顺序执行的，而增加了这些虚拟的列后，两个相邻的相同任务的间隔不可能减少，并且虚拟的列中任务也是满足冷却时间的要求，因此仍然顺序执行并跳过虚拟的列中剩余的“空余时间”一定是可行的
             */
            int max_val = count[25] - 1 , idle_slots = max_val * n;

            for (int i = 24; i >= 0 && count[i] > 0; i--) {
                idle_slots -= min(count[i], max_val);
            }

            return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
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

void test_leastInterval_3(Solution So) {
    vector<char> v = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'D', 'D', 'D', 'E', 'E', 'E', 'F', 'F'};
    cout << "size: " << So.leastInterval(v, 2) << endl;
}

void test_leastInterval_4(Solution So) {
    vector<char> v = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'D'};
    cout << "size: " << So.leastInterval(v, 2) << endl;

}
int main() {
    Solution So;
    test_leastInterval_4(So);
}