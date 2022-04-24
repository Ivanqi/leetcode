#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            int m = mat.size();
            int n = mat[0].size();
            if (m * n != r * c) {
                return mat;
            }

            vector<vector<int>> ret(r, vector<int>(c));
            for (int x = 0; x < m * n; ++x) {
                ret[x / c][x % c] = mat[x / n][x % n];
            }

            return ret;
        }
};