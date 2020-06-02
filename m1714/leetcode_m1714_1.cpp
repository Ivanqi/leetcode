#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<int> smallestK(vector<int>& arr, int k) {
            sort(arr.begin(), arr.end());
            arr.resize(k);
            return arr;
        }
};

void test_case_1(Solution So) {
   vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
   int k = 4;
   vector<int> ret = So.smallestK(arr, k); 
    for (auto x: ret) {
       cout << x << " ";
    }
    cout << endl;
}

int main() {

    Solution So;
    test_case_1(So);
}
