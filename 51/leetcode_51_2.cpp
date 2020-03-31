#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<string>> ret;
        // 输入棋盘边长n， 返回所有合法的放置
        vector<vector<string>> solveNQueens(int n) {
            // '.' 表示空， 'Q'表示皇后，初始化空棋盘
            vector<string> board(n, string(n, '.'));
            backtrack(board, 0);
            return ret;
        }

        /**
         * 路径: board中小于row的那些行都已经成功放置了皇后
         * 选择列表: 第row行的所有列都是放置皇后的选择
         * 结束条件: row超过board的最后一行
         */
        void backtrack(vector<string>& board, int row)
        {
            // 触发结束条件
            if (row == board.size()) {
                ret.push_back(board);
                return ;
            }

            int n = board[row].size();
            for (int col = 0; col < n; col++) {
                if (!isValid(board, row, col)) {
                    continue;
                }
                // 做选择
                board[row][col] = 'Q';
                // 进入下一行决策
                backtrack(board, row + 1);
                // 撤销选择
                board[row][col] = '.';
            }
        }

        // 是否可以在borad[row][col]放置皇后?
        bool isValid(vector<string>& board, int row, int col) {
            int n = board.size();

            // 检查列是否有皇后相互冲突
            for (int i = 0; i < n; i++) {
                if (board[i][col] == 'Q') return false;
            }

            // 检查右上方是否有皇后冲突
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }

            // 检查左上方是否有皇后冲突
            for (int i = row - 1, j = col - 1; i >= 0 &&  j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }

            return true;
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