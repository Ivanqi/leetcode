#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// double mysqrt(int x, int y) {
//     double dx = x - 0;
//     double dy = y - 0;
//     return sqrt(dx * dx + dy * dy);
// }

// bool compare(const vector<int>& a, const vector<int>& b) {
//     double aNum = mysqrt(a[0], a[1]);
//     double bNum = mysqrt(b[0], b[1]);

//     return aNum < bNum;
// }

class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            sort(points.begin(), points.end(), [](const vector<int>& s1, const vector<int>& s2) {
                return s1[0] * s1[0] + s1[1] * s1[1] < s2[0] * s2[0] + s2[1] * s2[1];
            });
            points.resize(K);
            return points;
        }
};

vector<vector<int>> test_case_1(Solution So) {
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int K = 1;

    vector<vector<int>> ret = So.kClosest(points, K);
    return ret;
}

vector<vector<int>> test_case_2(Solution So) {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int K = 2;

    vector<vector<int>> ret = So.kClosest(points, K);
    return ret;
}

int main() {

    Solution So;
    vector<vector<int>> ret = test_case_2(So);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}