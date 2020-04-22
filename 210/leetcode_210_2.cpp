#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;
/* 
    运用了贪心算法，每一步最优，则全局最优
    时间复杂度: O(V + E), E表示邻边的条数，V表示结点个数
    空间复杂度: O(V)
*/
class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> reverseAdj;
            int len = prerequisites.size();
            vector<int> ret;

            for (int i = 0; i < numCourses; i++) {
                vector<int> tmp;
                reverseAdj.push_back(tmp);
            }
            // 构建逆邻接表
            // 递归处理每个还没有被访问的结点，具体做法很简单：对于每个结点来说，先输出指向它的所有顶点，再输出自己
            // 如果这个顶点还没有被遍历过，就递归遍历它，把所有指向它的结点都输出了，再输出自己
            for (int i = 0; i < len; i++) {
                reverseAdj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }

            int visited[numCourses];
            memset(visited, 0, sizeof(visited));
            stack<int> res;
            
            for (int i = 0; i < numCourses; i++) {
                if (dfs(i, reverseAdj, visited, res)) {
                    return vector<int>();
                }
            }

            if (res.size() != numCourses) return vector<int>();

            for (int i = 0; i < numCourses; i++) {
                ret.push_back(res.top());
                res.pop();
            }
            return ret;
        }

        bool dfs(int vertex, vector<vector<int>>& reverseAdj, int *visited, stack<int>& res) {
            // 表示在访问的过程中没有遇到环，这个节点访问过了
            if (visited[vertex] == 2) return false;
            // 从正在访问到正在访问，表示遇到环了
            if (visited[vertex] == 1) return true;

            // 表示正在访问
            visited[vertex] = 1;
            // 后继结点的集合
            for (auto &w: reverseAdj[vertex]) {
                if (dfs(w, reverseAdj, visited, res)) {
                    // 层层递归返回 true, 表示图中有环
                    return true;
                }
            }
            // i 的所有后继结点都访问完了，都没有存在环，则这个结点就可以被标记为已经访问结束
            visited[vertex] = 2;
            res.push(vertex);
            // false表示图中不存在环
            return false;
        }
};

void test_case_1(Solution So) {
    vector<vector<int>> prerequisites = {
        {1, 0}
    };
    int numCourses = 2;
    vector<int> ret = So.findOrder(numCourses, prerequisites);


    for (auto v:ret) {
        cout << v << ' ';
    }
    cout << endl;
}

void test_case_2(Solution So) {
    vector<vector<int>> prerequisites = {
        {1, 0}, {2, 0}, {3, 1}, {3, 2}
    };
    int numCourses = 4;
    vector<int> ret = So.findOrder(numCourses, prerequisites);


    for (auto v:ret) {
        cout << v << ' ';
    }
    cout << endl;
}

void test_case_3(Solution So) {
    vector<vector<int>> prerequisites = {
        {1, 0}, {1, 2}, {0, 1}
    };
    int numCourses = 3;
    vector<int> ret = So.findOrder(numCourses, prerequisites);


    for (auto v:ret) {
        cout << v << ' ';
    }
    cout << endl;
}


int main() {

    Solution So;
    test_case_2(So);

    return 0;
}