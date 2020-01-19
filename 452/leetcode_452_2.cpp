#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            if (points.empty()) return 0;

            //排序：区间的左端点先按由小到大排序；相同的左端点，按右端点由小到大排序。
            sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] <= b[1];
            });

            int end = points[0][1];
            int count = 1, size = points.size();

            for (int i = 1; i < size; ++i) {
                if (end < points[i][0]) { // end 小于i号区间的左边界，贪心的选择i号区间的右边界
                    end = points[i][1];
                    count++;
                }
            }
            return count;
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
    test_case_1(So);

    return 0;
}