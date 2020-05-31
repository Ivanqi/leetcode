#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    public:
        priority_queue<int, vector<int>, greater<int>> Q;
        int K;
        KthLargest(int k, vector<int>& nums) {
            for (int x: nums) {
                Q.push(x);
                if (Q.size() > k) {
                    Q.pop();
                }
            }
            K = k;
        }
        
        int add(int val) {

            Q.push(val);
            if (Q.size() > K) Q.pop();
            return Q.top();
        }
};

void test_case_1() {
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kl(k, nums);

    cout << "返回的结果: " << kl.add(3) << endl;
    cout << "返回的结果: " << kl.add(5) << endl;
    cout << "返回的结果: " << kl.add(10) << endl;
    cout << "返回的结果: " << kl.add(9) << endl;
    cout << "返回的结果: " << kl.add(4) << endl;
}

int main() {

    test_case_1();
    return 0;
}
