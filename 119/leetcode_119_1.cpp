#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<vector<int>> C(rowIndex + 1);

            for (int i = 0; i <= rowIndex; i++) {
                C[i].resize(i + 1);
                C[i][0] = C[i][i] = 1;
                for (int j = 1; j < i; j++) {
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                }
            }    
  
            return C[rowIndex];
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