#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            return helper(s, t) && helper(t, s);
        }

        bool helper(string s, string t) {
            int n = s.length();
            unordered_map<char, char> map;
            for (int i = 0; i < n; i++) {
                char c1 = s[i];
                char c2 = t[i];

                if (map.count(c1)) {
                    if (map[c1] != c2) {
                        return false;
                    }
                } else {
                    map[c1] = c2;
                }
            }

            return true;
        }
};

void test_case_1(Solution So) {
    string s = "egg";
    string t = "add";

   cout << "结果: " << So.isIsomorphic(s, t) << endl; 
}

void test_case_2(Solution So) {
    string s = "foo";
    string t = "bar";

   cout << "结果: " << So.isIsomorphic(s, t) << endl; 
}

int main() {

    Solution So;
    test_case_2(So);
    return 0;
}