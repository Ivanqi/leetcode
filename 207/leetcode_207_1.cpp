#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
/* 
    运用了贪心算法，每一步最优，则全局最优
    时间复杂度: O(V + E), E表示邻边的条数，V表示结点个数
    空间复杂度: O(V)
*/
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj;
            int len = prerequisites.size();
            vector<int> ret;
            vector<int>inDegree(numCourses, 0); // 统计每个顶点的入度


            for (int i = 0; i < numCourses; i++) {
                vector<int> tmp;
                adj.push_back(tmp);
            }

            for (int i = 0; i < len; i++) {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
                inDegree[prerequisites[i][0]]++;
            }


            queue<int> Q;
            // 找出入度为0的顶点
            for (int i = 0; i < numCourses; ++i) {
                if (inDegree[i] == 0) Q.push(i);
            }
            
            int m = 0;
            while (!Q.empty()) {
                int i = Q.front();
                Q.pop();
                ret.push_back(i);
                m++;
                for (int j = 0; j < adj[i].size(); j++) {
                    int w = adj[i][j];
                    if (!(--inDegree[w])) {
                        Q.push(w);
                    }
                }
            }
            // 有回路
            if (m != numCourses) {
                return false;  
            }
            return ret.size() > 0 ? true : false;
        }
};

void test_case_1(Solution So) {
    vector<vector<int>> prerequisites = {
        {1, 0}
    };
    int numCourses = 2;
    bool ret = So.canFinish(numCourses, prerequisites);

    cout << "结果为：" << ret << endl;
}

void test_case_2(Solution So) {
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };
    int numCourses = 4;
    bool ret = So.canFinish(numCourses, prerequisites);

    cout << "结果为：" << ret << endl;
}

void test_case_3(Solution So) {
    vector<vector<int>> prerequisites = {
        {1, 0}, {1, 2}, {0, 1}
    };
    int numCourses = 3;
    bool ret = So.canFinish(numCourses, prerequisites);

    cout << "结果为：" << ret << endl;
}


int main() {

    Solution So;
    test_case_1(So);

    return 0;
}