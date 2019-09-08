#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

/**
 * 递减栈
 *  1. 元素入栈之后，其下面的元素一定是其左边第一个比它小的数；(可用来求每个元素左边更小的第一个元素)
 *  2. 若在元素插入之前，栈顶元素比插入元素更大，那么栈顶元素一定是待插入元素左边一个更大的数
 *  3. 若在元素插入之前，栈顶元素比插入元素更大，那么栈顶元素一定是所有需要出栈的元素右边更小的数；(可用来求每个元素右边更小的第一个元素)
 *  4. 最后一定会留下最小的数（对较小 的数更有利）
 */
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            map<int,int> PMap;
            stack<int> DStack;
            vector<int> result;
            for (int i=nums2.size()-1;i>=0;i--) {
                if (DStack.empty()){
                    PMap.insert({nums2[i],-1});
                    DStack.push(nums2[i]);
                }
                else if (DStack.top()>nums2[i]) {
                    PMap.insert({nums2[i],DStack.top()});
                    DStack.push(nums2[i]);
                }
                else {
                    while(!DStack.empty()&&DStack.top()<nums2[i])
                    DStack.pop();
                    if(DStack.empty())
                    PMap.insert({nums2[i],-1});
                    else
                    PMap.insert({nums2[i],DStack.top()}); 
                    DStack.push(nums2[i]);
                }
            }
            for (int i=0;i<nums1.size();i++)
                result.push_back(PMap[nums1[i]]);   //map的下标操作返回值是和value的类型一样的
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
    test_case_1(So);
    return 0;
}