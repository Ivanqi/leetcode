#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int row[9][10] = {0};   // 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一数都没有出现过
            // 整个borad有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应
            int col[9][10] = {0};   // 存储每一列的每个数是否出现过
            int box[9][10] = {0};   // 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    // 遍历到第i行第j列的那个数，我们要判断这个数在其所在的行有没有出现过
                    // 同时判断这个数在其所在的列有没有出现过
                    // 同时判断这个数在其所在的box中有没有出现过
                    if (board[i][j] == '.') continue;
                    int curNumber = board[i][j] - '0';

                    if (row[i][curNumber]) return false;
                    if (col[j][curNumber]) return false;
                    if (box[ j / 3 + (i / 3) * 3][curNumber]) return false;

                    row[i][curNumber] = 1;  // 之前都没有出现过，现在出现了，就给它置为1，下次遇到就能够直接返回false了
                    col[j][curNumber] = 1;
                    box[ j / 3 + (i / 3) * 3][curNumber] = 1;
                }
            }
            return true;
        }
};

void test_case_1(Solution So) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool ret = So.isValidSudoku(board);
    cout << "结果: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool ret = So.isValidSudoku(board);
    cout << "结果: " << ret << endl;
}

int main () {

    Solution So;

    test_case_2(So);
    return 0;
}