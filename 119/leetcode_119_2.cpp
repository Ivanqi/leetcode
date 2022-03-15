#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> pre, cur;

            for (int i = 0; i <= rowIndex; i++) {
                cur.resize(i + 1);
                cur[0] = cur[i] = 1;
                for (int j = 1; j < i; j++) {
                    cur[j] = pre[j - 1] + pre[j];
                }
                pre = cur;
            }    
  
            return pre;
        }
};

void test_case_1(Solution So) {
    int rowIndex = 3;
    vector<int> ret = So.getRow(rowIndex);

    for (auto x: ret) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {

    Solution So;
    test_case_1(So);    
}