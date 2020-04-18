#include <iostream>
#include <vector>
using namespace std; 

class Solution {
    private:
        int *result;
        int nums;
        vector<vector<string>> ret;
    public:
        void printNQueens(int *res) {
            vector<string> tmpV;

            for (int row = 0; row < nums; row++) {
                string tmp = "";
                for (int column = 0; column < nums; column++) {
                    if (res[row] == column) {
                        tmp += 'Q';
                    } else {
                        tmp += '.';
                    }
                }
                tmpV.push_back(tmp);
            }
            ret.push_back(tmpV);
        }

        bool check(int row, int column) {
            int leftUp = column - 1, rightUp = column + 1;

            for (int i = row - 1; i >= 0; i--) {
                if (result[i] == column) return false;

                if (leftUp >= 0) {
                    if (result[i] == leftUp) return false;
                }
                
                if (rightUp < nums) {
                    if (result[i] == rightUp) return false;
                }
               
                --leftUp;
                ++rightUp;
            }
            return true;
        }
        
        void helper(int row) {
            if (row == nums) {
                printNQueens(result);
                return;
            }

            for (int column = 0; column < nums; column++) {
                if (check(row, column)) {
                    result[row] = column;
                    helper(row + 1);
                }
            }
        }
        
        vector<vector<string>> solveNQueens(int n) {
            nums = n;
            result = new int(n);
            helper(0);
            return ret;
        }
};

vector<vector<string>> test_case_1(Solution So) {
    int n = 4;
    return So.solveNQueens(n);
}

int main() {
    Solution So;
    vector<vector<string>> ret = test_case_1(So);
    int retLen = ret.size();
    cout << "[";

    for (int i = 0; i < retLen; i++) {
        vector<string> tmpV = ret[i];
        int rLen = ret[i].size();
        cout << endl << " [";
        for (int j = 0; j < rLen; j++) {
            cout << " " << tmpV[j] << "," << endl;
        }
        cout << " ]" << endl;
    }

    cout  << "]" << endl;
}