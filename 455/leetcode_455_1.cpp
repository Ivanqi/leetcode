#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());

            int child = 0;
            int cookie = 0;

            while (child < g.size() && cookie < s.size()) { 
                if (s[cookie] >= g[child]) {
                    child++;
                }
                cookie++;
            }

            return child;
        }
};

void test_case_1() {
    vector<int> g;
    vector<int> s;

    g.push_back(1);
    g.push_back(2);
    g.push_back(3);
    s.push_back(1);
    s.push_back(1);

    Solution So;

    cout << So.findContentChildren(g, s) << endl;

}

void test_case_2() {
    vector<int> g;
    vector<int> s;

    g.push_back(1);
    g.push_back(2);
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    Solution So;

    cout << So.findContentChildren(g, s) << endl;

}

void test_case_3() {
    vector<int> g;
    vector<int> s;

    g.push_back(10);
    g.push_back(9);
    g.push_back(8);
    g.push_back(7);

    s.push_back(5);
    s.push_back(6);
    s.push_back(7);
    s.push_back(8);

    Solution So;

    cout << So.findContentChildren(g, s) << endl;
}

int main () {
    test_case_3();
    return 0;
}