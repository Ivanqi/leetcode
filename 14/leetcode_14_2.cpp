#include <iostream>
#include <vector>
using namespace std;

/**
 * 时间复杂度: O(S), S是所有字符串中字符数量的总和
 * 最坏时间复杂度:
 *  最坏情况下，n个字符串都是相同的
 *  算法会将S1与其他字符串[S2...Sn]都做一次比较
 *  这样就会进行S次字符比较，其中S是输入数据所有字符数量
 * 空间复杂度: O(1)
 */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {

            string r = strs.size() ? strs[0]: "";

            for (auto s: strs) {
                while (s.substr(0, r.size()) != r) {
                    r = r.substr(0, r.size() - 1);
                    if (r == "") return r;
                }
            }
            return r;
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