#include <iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        int col = 0;
        vector<vector<string>> ret;
        int *result;
    public:
        void printNQueens(int *result)
        {
            int row, column;
            vector<string> tmpV;
            for (row = 0; row < col; ++row) {
                string tmp = "";
                for (column = 0; column < col; ++column) {
                    if (result[row] == column) {
                        tmp += 'Q';
                    } else {
                        tmp += '.';
                    }
                }
                tmpV.push_back(tmp);
            }
            ret.push_back(tmpV);
        }
        // 检测，纵行， 左上，右上
        bool isOk(int row, int column)
        {
            int leftUp = column - 1, rightUp = column + 1;

            for (int i = row - 1; i >= 0; i--) {
                // 纵行
                if (result[i] == column) return false;

                // 左上
                if (leftUp >= 0) {
                    if (result[i] == leftUp) return false;
                }
                
                // 右上
                if (rightUp < col) {
                    if (result[i] == rightUp) return false;
                }
                --leftUp;
                ++rightUp;
            }
            return true;
        }

        void calNQueens(int row) 
        {
            if (row == col) {
               printNQueens(result); 
               return;
            }
            for (int column = 0; column < col; ++column) {
                if (isOk(row, column)) {
                    result[row] = column;
                    calNQueens(row + 1);
                }
            }
        }

        vector<vector<string>> solveNQueens(int n) {
            result = new int(n);
            col = n;
            calNQueens(0);
            return ret;
        }
};

vector<vector<string>> test_case_1(Solution So)
{
    int n = 4;
    vector<vector<string>> ret = So.solveNQueens(n);

    return ret;
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