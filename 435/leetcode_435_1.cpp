#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            if (intervals.empty()) return 0;
            sort(intervals.begin(), intervals.end());

            int left = intervals[0][1];
            int res = 0;
            // cout << "left: " << left << endl;
            for (int i = 1; i < intervals.size(); ++i) {
                if (intervals[i][0] < left) {
                    // cout << "intervals[" << i << "][0]" << intervals[i][0] << " / " << left << endl;
                    ++res;
                    left = min(left, intervals[i][1]);
                } else {
                    left = intervals[i][1];
                }
            }
            return res;
        }
};

void test_case_1(Solution So) {
    vector<int> num1 {1, 2};
    vector<int> num2 {2, 3};
    vector<int> num3 {3, 4};
    vector<int> num4 {1, 3};

    vector<vector<int>> intervals;
    intervals.push_back(num1);
    intervals.push_back(num2);
    intervals.push_back(num3);
    intervals.push_back(num4);

    cout << So.eraseOverlapIntervals(intervals) << endl;
}

void test_case_2(Solution So) {
    vector<int> num1 {1, 2};
    vector<int> num2 {1, 2};
    vector<int> num3 {1, 2};

    vector<vector<int>> intervals;
    intervals.push_back(num1);
    intervals.push_back(num2);
    intervals.push_back(num3);

    cout << So.eraseOverlapIntervals(intervals) << endl;
}

void test_case_3(Solution So) {
    vector<int> num1 {1, 2};
    vector<int> num2 {2, 3};

    vector<vector<int>> intervals;
    intervals.push_back(num1);
    intervals.push_back(num2);

    cout << So.eraseOverlapIntervals(intervals) << endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}