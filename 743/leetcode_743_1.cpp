#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 邻接表
class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int N, int K) {
            vector<vector<pair<int, int>>> adj;
            for (int i = 0; i < N + 1;i++) {
                vector<pair<int, int>> tmp;
                adj.push_back(tmp);
            }

            int dis[N + 1];
            for (int i = 0; i < N + 1; i++) {
                dis[i] = -1;
            }
            dis[K] = 0;

            for (int i = 0; i < times.size(); i++) {
                // u 是源节点, v 是目标节点, w 是一个信号从源节点传递到目标节点的时间
                int u = times[i][0];
                int v = times[i][1];
                int w = times[i][2];
                pair<int, int> t(v, w);
                adj[u].push_back(t);
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

            q.push(pair<int, int>(K, 0));

            while(!q.empty()) {
                pair<int, int> min = q.top();
                q.pop();

                for (int i = 0; i < adj[min.first].size(); i++) {
                    pair<int, int> next = adj[min.first][i];
                    next.second += min.second;
                    if (dis[next.first] == -1 || next.second < dis[next.first]) {
                        dis[next.first] = next.second;
                        q.push(next);
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

void test_case_4(Solution So) {
    vector<vector<int>> times = {
        {1, 2, 1}, {2, 1, 3}
    };
    int N = 2;
    int K = 2;
    int ret = So.networkDelayTime(times, N, K);
    cout << "结果为: " << ret << endl;
}

int main() {

    Solution So;
    test_case_4(So);
    return 0;
}