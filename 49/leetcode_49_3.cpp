#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            int sub = 0;    // 结果vector的下标值
            string tmp;     // 临时string
            unordered_map<string, int> work;    // 判断排序后单词是否存在，即字母组成是否一致

            for (auto str:strs) {
                tmp = str;
                sort(tmp.begin(), tmp.end());
                if (work.count(tmp)) {
                    res[work[tmp]].push_back(str);
                } else {
                    vector<string> vec(1, str);
                    res.push_back(vec);
                    work[tmp] = sub++;
                }
            }
            return res;
        }
};

void test_case_1(Solution So) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ret = So.groupAnagrams(strs);
    for (auto r:ret) {
        for (auto val:r) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test_case_2(Solution So) {
    vector<string> strs = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    vector<vector<string>> ret = So.groupAnagrams(strs);
    for (auto r:ret) {
        for (auto val:r) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {
    Solution So;
    test_case_1(So);
}