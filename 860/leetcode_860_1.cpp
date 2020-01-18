#include <iostream>
#include <vector>
using namespace std;

/**
 * 贪心思维
 *  1. 总是优先找零10元，如果没有10元或找零钱金额小于10元的，才找零5元。因为2个5元可以组成10元
 *  2. 给20元找零的时候，总是优先找 10 + 5的组合
 */
class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int five = 0, ten = 0;
            for (int i = 0; i < bills.size(); i++) {
                if (bills[i] == 5) five++;
                else if (bills[i] == 10) {
                    if (five == 0) return false;
                    five--;
                    ten++;
                } else  {
                    if (five > 0 && ten > 0) {
                        five--;
                        ten--;
                    } else if (five >= 3) {
                        five -= 3;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
};


void test_case_1(Solution So) {
    vector<int> bills {5, 5, 10};
    cout << So.lemonadeChange(bills) << endl; 
}

void test_case_2(Solution So) {
    vector<int> bills {10, 10};
    cout << So.lemonadeChange(bills) << endl; 
}

void test_case_3(Solution So) {
    vector<int> bills {5, 5, 10, 10, 20};
    cout << So.lemonadeChange(bills) << endl; 
}

void test_case_4(Solution So) {
    vector<int> bills {5, 5, 5, 10, 5, 5, 10, 20, 20, 20};
    cout << So.lemonadeChange(bills) << endl; 
}

int main() {

    Solution So;
    test_case_4(So);
    return 0;
}