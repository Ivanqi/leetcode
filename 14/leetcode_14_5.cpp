#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二分查找
/**
 * 最坏时间复杂度
 *  O(S * log(n)), 其中S所有字符串中字符数量的总和
 *  算法一共会进行log(n)次迭代，每次都会进行 S = m * n次比较，所有总时间负责度为 O(S *log(n))
 * 空间复杂度: O(1)
 */
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) return "";

            int minLen = 9999;
            for (auto str: strs) {
                int str_len = str.size();
                minLen = min(minLen, str_len);
            }

            int low = 1;
            int high = minLen;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (isCommonPrefix(strs, mid)) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            return strs[0].substr(0, (low + high) / 2);
        }

        bool isCommonPrefix(vector<string>& strs, int len) {
            string tmp = strs[0].substr(0, len);

            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].substr(0, len) != tmp) {
                    return false;
                }
            }

            return true;
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