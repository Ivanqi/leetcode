#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 分治法
/**
 * 时间复杂度：O(S)
 * 最好时间复杂度
 *  算法会进行 minLen * n次比较，其中minLen是数组中最短字符串长度
 * 最坏时间复杂度
 *  O(S), S是所有字符串数量的总和， S = m * n
 * 空间复杂度: O(m * log(n))
 *  内存开支主要是递归过程中使用的栈空间所消耗的
 *  一个会进行log(n)次递归，每次需要m的空间存储返回结果
 *  所以空间复杂度 O(m * log(n))
 */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) return "";
            return longestCommonPrefix(strs, 0, strs.size() - 1);
        }

        string longestCommonPrefix(vector<string>& strs, int left, int right) {
            if (left == right) {
                return strs[left];
            } else {
                int mid = (left + right) / 2;
                string leftPrefix = longestCommonPrefix(strs, left, mid);
                string rightPrefix = longestCommonPrefix(strs, mid + 1, right);
                return CommonPrefix(leftPrefix, rightPrefix);
            }
        }

        string CommonPrefix(string leftPrefix, string rightPrefix) {

            int minSize = min(leftPrefix.size(), rightPrefix.size());

            for (int i = 0; i < minSize; i++) {
                if (leftPrefix[i] != rightPrefix[i]) {
                    return leftPrefix.substr(0, i);
                }
            }
            return leftPrefix.substr(0, minSize);
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