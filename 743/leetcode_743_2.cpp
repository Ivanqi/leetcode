#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 邻接矩阵
class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int N, int K) {
            int dis[107];
            int len = times.size();
            for (int i = 1; i <= 100; i++) {
                dis[i] = -1;
            }

            dis[K] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
            pair<int, int> t(0, K);
            que.push(t);

            while (!que.empty()) {
                t = que.top();
                que.pop();

                int u = t.second;
                int uw = t.first;

                if (t.first > dis[u]) {
                    continue;
                }

                for (int i = 0; i < len; i++) {
                    if (times[i][0] == u) {
                        int v = times[i][1];
                        int w = times[i][2] + uw;
                        if (dis[v] == -1 || w < dis[v]) {
                            dis[v] = w;
                            que.push(pair<int, int>(w, v));
                        }
                    }
                }
            }

            int ans = 0;
            int flag = 1;
            for (int i = 1; i <= N; i++) {
                if (dis[i] > ans) ans = dis[i];
                if (dis[i] == -1) flag = 0;
            }

            if (flag) return ans;
            else return -1;
        }
};

void test_case_1(Solution So) {
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int N = 4;
    int K = 2;

    int ret = So.networkDelayTime(times, N, K);
    cout << "结果为: " << ret << endl;
}

void test_case_2(Solution So) {
    vector<vector<int>> times = {
        {0, 1, 10},
        {0, 4, 15},
        {1, 2, 15},
        {1, 3, 2},
        {3, 5, 12},
        {2, 5, 5},
        {4, 5, 10}
    };
    int N = 5;
    int K = 0;

    int ret = So.networkDelayTime(times, N, K);
    cout << "结果为: " << ret << endl;
}

void test_case_3(Solution So) {
    vector<vector<int>> times = {
        {1, 2, 1},
    };
    int N = 2;
    int K = 2;

    int ret = So.networkDelayTime(times, N, K);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_3(So);
    return 0;
}