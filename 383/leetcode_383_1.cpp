#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if (ransomNote.size() > magazine.size()) {
                return false;
            }

            unordered_map<int, int> m;

            for (char ch: magazine) {
                m[ch - 'a']++;
            }

            for (auto &ch : ransomNote) {
                m[ch - 'a']--;
                if (m[ch - 'a'] < 0) {
                    return false;
                }
            }

            return true;
        }
};