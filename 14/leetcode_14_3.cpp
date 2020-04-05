#include <iostream>
#include <vector>
using namespace std;

/**
 * 时间复杂度:O(S), S是所有字符串中字符数量的总和
 * 最坏时间复杂度
 *  最坏情况下，输入数据为n个长度为m的相同字符串，算法会进行S = m * n次比较
 * 最好时间复杂度
 *  算法只进行n * minLen次比较，其中minLen是数组中最短字符串长度
 * 空间复杂度: O(1)
 */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {

            if (strs.size() == 0) return "";
            for (int i = 0; i < strs[0].size(); i++) {
                char c = strs[0][i];
                for (int j = 1; j < strs.size(); j++) {
                    if (i == strs[j].size() || strs[j][i] != c) {
                        return strs[0].substr(0, i);
                    }
                }
            }
            return strs[0];
        }
};

void test_case_1(Solution So) {
    vector<string> strs = {
        "flower", "flow", "flight"
    };

    string ret = So.longestCommonPrefix(strs);
    cout << ret << endl;
}

void test_case_2(Solution So) {
    vector<string> strs = {
        "dog", "racecar", "car"
    };

    string ret = So.longestCommonPrefix(strs);
    cout << ret << endl;
}

void test_case_3(Solution So) {
    vector<string> strs = {
        "a"
    };
    string ret = So.longestCommonPrefix(strs);
    cout << ret << endl;
} 

int main () {
    Solution So;
    test_case_1(So);
}