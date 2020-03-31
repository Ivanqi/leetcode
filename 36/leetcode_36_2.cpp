#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            for (int i = 0; i < 9; i++) {
                // hori, veti, sqre分贝表示行，列，小宫
                int hori = 0, veti = 0, sqre = 0;
                for (int j = 0; j < 9; j++) {
                    // 由于传入为char,需要转换为int，减48
                    int h = board[i][j] - 48;
                    int v = board[j][i] - 48;
                    int s = board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] - 48;
                    // "." 的 ASCII码为46，故小于0代表着当前的符号位"."

                    if (h > 0) {
                        hori = sodokuer(h, hori);
                    }

                    if (v > 0) {
                        veti = sodokuer(v, veti);
                    }

                    if (s > 0) {
                        sqre = sodokuer(s, sqre);
                    }

                    if(hori == -1 || veti == -1 || sqre == -1){
                        return false;
                    }
                }
            }
            return true;
        }

        int sodokuer(int n, int val) {
            return ((val >> n) & 1) == 1 ? -1 : val ^ (1 << n);
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

    test_case_1(So);
    return 0;
}