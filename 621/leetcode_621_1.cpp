#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

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
            // 最多有25个任务和最高频率任务相同
            int temp = 25;

            // 统计最高频率任务的个数
            while (temp > 0 && count[25] == count[temp]) {
                temp--;
            }

            // 根据计算所得结果
            // 总排队时间 = (桶个数 - 1) * (n + 1) + 最后一桶的任务数
            int result = (count[25] - 1) * (n + 1) + 25 - temp;
            // 任务数组长度
            int length = tasks.size();
            // 返回两个较大的
            return result > length ? result : length;
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
    test_leastInterval_2(So);
}