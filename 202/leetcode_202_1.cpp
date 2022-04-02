#include <iostream>
#include <set>
using namespace std;

class Solution {
    public:
        int getNext(int n) 
        {
            int totalSum = 0;
            while (n > 0) {
                int d = n % 10;
                n = n / 10;
                totalSum += d * d;
            }

            return totalSum;
        }

        bool isHappy(int n) {
            set<int> seen;

            while (n != 1 && seen.find(n) == seen.end()) {
                seen.insert(n);
                n = getNext(n);
            }

            return n == 1;
        }
};

void test_case_1(Solution So) {
    int n = 19;
    bool ret = So.isHappy(n);
    cout << "结果: " << ret << endl;
}

void test_case_2(Solution So) {
    int n = 2;
    bool ret = So.isHappy(n);
    cout << "结果: " << ret << endl;
}

int main() {
    Solution So;
    test_case_2(So);
    return 0;
}