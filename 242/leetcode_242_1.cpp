#include <iostream>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false;
            int count[26] = {0};
            for (int i = 0; i < s.size(); i++) {
                count[s[i] - 'a']++;
                count[t[i] - 'a']--;
            }

            for (int i = 0; i < 26; i++) {
                if (count[i] != 0) return false;
            }
            return true;
        }
};

void test_case_1(Solution So) {
    string s = "anagram";
    string t = "nagaram";

    cout << "val: " << So.isAnagram(s, t) << endl;
}

void test_case_2(Solution So) {
    string s = "rat";
    string t = "car";

    cout << "val: " << So.isAnagram(s, t) << endl;
}

int main() {
    Solution So;
    test_case_2(So);
    return 0;
}