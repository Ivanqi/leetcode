#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> pt;

        int dist(int i) {
            return pt[i].front() * pt[i].front() + pt[i].back() * pt[i].back();
        }

        int partition(int left, int right) {
            int pivot = dist(left);
            vector<int> pivotPoint = pt[left];

            while (left < right) {
                while (left < right && dist(right) > pivot) {
                    right--;
                }

                pt[left] = pt[right];

                while (left < right && dist(left) <= pivot) {
                    left++;
                }

                pt[right] = pt[left];
            }

            pt[left] = pivotPoint;

            return left;
        }

        void helper(int left, int right, int k) {
            if (left >= right) return;

            int pivot = partition(left, right);
            if (pivot == k) return;
            else if (pivot < k) {
                return helper(pivot + 1, right, k);
            } else {
                return helper(left, pivot - 1, k);
            }
        }

        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            pt = points;
            helper(0, points.size() - 1, K - 1);
            pt.resize(K);
            return pt;
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

vector<vector<int>> test_case_3(Solution So) {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}, {7, 8}, {2, 8}, {9, 4}, {-9, -8}};
    int K = 2;

    vector<vector<int>> ret = So.kClosest(points, K);
    return ret;
}

int main() {

    Solution So;
    vector<vector<int>> ret = test_case_2(So);

    cout << "结果为: " << endl;
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}