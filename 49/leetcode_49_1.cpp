#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,vector<string> > ma;
            vector<vector<string>> res;

            for(auto str:strs){
                string tmp = str;
                sort(tmp.begin(),tmp.end());
                ma[tmp].push_back(str);
            }

            for(const auto& m:ma) {
                res.push_back(m.second);
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
int main() {
    Solution So;
    test_case_1(So);
}