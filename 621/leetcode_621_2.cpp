#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            int count[26] = {0}, max = 0;
            int len = tasks.size();
            for (int i = 0; i < tasks.size(); i++) {
                count[tasks[i] - 'A']++;
                if (count[tasks[i] - 'A'] > max) max = count[tasks[i] - 'A'];
            }

            int res = (max - 1) * (n + 1);
            int i = 25;
            for (int i = 0; i < 26; i++) {
                if (count[i] == max) res++;
            }
            return res > len ? res: len;
        }
};

void test_leastInterval(Solution So) {
    vector<char> v;
    v.push_back('A');
    v.push_back('A');
    v.push_back('A');
    v.push_back('B');
    v.push_back('B');
    v.push_back('B');
    cout << "size: " << So.leastInterval(v, 2) << endl;
}

int main() {
    Solution So;
    test_leastInterval(So);
}