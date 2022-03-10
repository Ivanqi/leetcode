#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int dLen = digits.size();
            for (int i = dLen - 1; i >= 0; i--) {
                if (digits[i] != 9) {
                    digits[i]++;

                    for (int j = i + 1; j < dLen; j++) {
                        digits[j] = 0;
                    }

                    return digits;
                }
                
            }
            vector<int> ans(dLen + 1);
            ans[0] = 1;
            return ans;
        }
        
};

void test_case_1(Solution So) {
    vector<int> arr = {1, 2, 3};

    So.plusOne(arr);
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

void test_case_2(Solution So) {
    vector<int> arr = {4,3,2,1};

    So.plusOne(arr);
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

void test_case_3(Solution So) {
    vector<int> arr = {0};

    So.plusOne(arr);
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

void test_case_4(Solution So) {
    vector<int> arr = {1, 2, 3, 9, 9};

    So.plusOne(arr);
    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}