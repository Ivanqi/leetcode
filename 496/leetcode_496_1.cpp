#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

/**
 * 递增栈: (从栈顶到栈顶递增)
 *  1. 元素入栈之后，其下面元素一定是其左边第一个比它大的数；(可用来求每个元素左边更大的第一个元素)
 *  2. 若在元素插入之前，栈顶元素比插入元素小，那么栈顶元素一定是插入元素左边第一个比它小的数
 *  3. 若在元素插入之前，栈顶元素比插入元素小，那么待插入元素是所有需要出栈的元素右边第一个更大的数(可用来求每个元素右边更大的第一个元素)
 *  4. 最后一定会留下最大的数
 */

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            map<int, int> PMap;
            stack<int> UpStack;
            vector<int> result;
            for (int i = 0; i < nums2.size(); i++) {
                if (UpStack.empty() || UpStack.top() > nums2[i]) {
                    UpStack.push(nums2[i]);
                } else {
                    while (!UpStack.empty() && UpStack.top() < nums2[i]) {
                        PMap.insert({ UpStack.top(), nums2[i] });
                        UpStack.pop();
                    }
                    UpStack.push(nums2[i]);
                }
            }

            while(!UpStack.empty()) {
                PMap.insert({ UpStack.top(), -1 });
                UpStack.pop();
            }

            for(int i = 0; i < nums1.size(); i++) {
                result.push_back(PMap[nums1[i]]);   // map的下标操作返回值是和value的类型一样的
            }
            return result;
        }
};

void test_case_1(Solution So) {
    vector<int> s1;
    vector<int> s2;
    vector<int> s3;

    s1.push_back(4);
    s1.push_back(1);
    s1.push_back(2);

    s2.push_back(1);
    s2.push_back(3);
    s2.push_back(4);
    s2.push_back(2);

    s3 = So.nextGreaterElement(s1, s2);

    for (int i = 0; i < s3.size(); i++) {
        cout << "val: " << s3[i] << endl;
    }
}

void test_case_2(Solution So) {

    vector<int> s1;
    vector<int> s2;
    vector<int> s3;

    s1.push_back(2);
    s1.push_back(4);

    s2.push_back(1);
    s2.push_back(2);
    s2.push_back(3);
    s2.push_back(4);

    s3 = So.nextGreaterElement(s1, s2);

    for (int i = 0; i < s3.size(); i++) {
        cout << "val: " << s3[i] << endl;
    }

}

int main () {

    Solution So;
    test_case_2(So);
    return 0;
}