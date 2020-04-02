#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans(numRows);

            for (int i = 0; i < numRows; i++) {
                ans[i] = vector<int>(i + 1, 1);;
            }

            for (int i = 2; i < numRows; i++) {
                for (int j = 1; j < ans[i - 1].size(); j++) {
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }
            return ans;
        }
};


vector<vector<int>> test_case_1(Solution So) {
    int n = 5;
    return So.generate(n);
}

vector<vector<int>> test_case_2(Solution So) {
    int n = 2;
    return So.generate(n);
}

int main() {

    Solution So;
    vector<vector<int>> ret = test_case_1(So);


    cout << "[ \n";
    
    for (int i = 0; i < ret.size(); i++) {
        vector<int> retn = ret[i];
        cout << "\t[ ";
        for (int j = 0; j < retn.size(); j++) {
            cout << retn[j] << ", ";
        }
        cout << "]\n";
    }
    cout << "\n]";

    return 0;
}