#include <iostream>
#include<algorithm>
using namespace std;

int main ()
{
    int testArr[9] = {1,8,6,2,5,4,8,3,7};
    size_t len = sizeof(testArr) / sizeof(int);
    int low = 0, high = len - 1, maxArea = 0;
    while (low < high) {
        maxArea = max(maxArea, min(testArr[low], testArr[high]) * (high - low));
        if (testArr[low] < testArr[high]) {
            low++;
        } else {
            high--;
        }
    }
    cout << "返回的结果:" << maxArea << endl;
    return 0;
}