#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<unsigned,vector<string> > ma;
            vector<vector<string>> res;
            int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                73, 79, 83, 89, 97, 101};
            

            for(auto str:strs){
                unsigned index = 1;
                for (auto s:str) {
                    index *= primes[s - 'a'];
                }
                ma[index].push_back(str);
            }

            for( const auto& m:ma) {
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
    test_case_2(So);
}