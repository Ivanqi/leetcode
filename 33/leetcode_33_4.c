#include <stdlib.h>
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;                
            }
        } else {
           if (target <= nums[right] && nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            } 
        }
    }
    return -1;
}

void test_case_1() {
    int t1[] = {7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
    int len = 11;
    int i;
    int index = -1;
    for (i = -1; i < 11; i++) {
        index = search(t1, i, len);
        printf("Find %d at index %d\n", i, index);
    }
}

void test_case_2() {
    int t1[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int len = 7;
    printf("Find %d at index %d\n", target, search(t1, len, target));
}

void test_case_3() {
    int t1[] = {5, 1, 3};
    int target = 3;
    int len = 3;
    printf("Find %d at index %d\n", target, search(t1, len, target));
}

int main() {
    test_case_3();
}