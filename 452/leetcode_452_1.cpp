#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            if (points.empty()) return 0;
            sort(points.begin(), points.end());
            int left = points[0][1];
            int res = 1;

            for (int i = 1; i < points.size(); ++i) {
                if (points[i][0] <= left) {
                    left = min(left, points[i][1]);
                } else {
                    ++res;
                    left = points[i][1];
                }
            }
            return res;
        }
};

void test_case_1(Solution So) {

    vector<vector<int>> points;
    vector<int> num1 {10, 16};
    vector<int> num2 {2, 8};
    vector<int> num3 {1, 6};
    vector<int> num4 {7, 12};
    points.push_back(num1);
    points.push_back(num2);
    points.push_back(num3);
    points.push_back(num4);

    cout << So.findMinArrowShots(points) << endl;

}

void test_case_2(Solution So) {
    vector<vector<int>> points;
    vector<int> num1 {1, 2};
    vector<int> num2 {3, 4};
    vector<int> num3 {5, 6};
    vector<int> num4 {7, 8};
    points.push_back(num1);
    points.push_back(num2);
    points.push_back(num3);
    points.push_back(num4);

    cout << So.findMinArrowShots(points) << endl;
}

int main() {

    Solution So;
    test_case_2(So);

    return 0;
}