#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
    public:
        struct cmp {
            bool operator () (vector<int>& s1, vector<int>& s2) {
                return s1[0] * s1[0] + s1[1] * s1[1] < s2[0] * s2[0] + s2[1] * s2[1];
            }
        };
        
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            priority_queue<vector<int>,vector<vector<int>>, cmp> Q;

            int len = points.size();
            for (int i = 0; i < len; i++) {
                Q.push(points[i]);
                if (Q.size() > K) {
                    Q.pop();
                }
            }

            vector<vector<int>> ret;
            for (int i = 0; i < K; i++) {
                ret.push_back(Q.top());
                Q.pop();
            }
            return ret;
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
    vector<vector<int>> ret = test_case_1(So);

    cout << "结果为: " << endl;
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}