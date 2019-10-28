#include <stdlib.h>
#include <stdio.h>

/**
 * 发现循环数组存在一个性质，以数组中间点分区，会将数组分成一个有序数组和一个循环有序数组
 *  1. 如果首元素小于mid,说明前半部分是有序的，后半部分是循环有序数组
 *  2. 如果首元素大于mid，说明后半部分是有序的，前半部分是循环有序的数组
 *  3. 如果目标元素在有序数组范围中，使用二分查找
 *  4. 如果目标元素在循环有序数组中，设定数组边界后，使用以上方法查找
 */


int search(int nums[], int target, int sizeNum) {

    int low = 0;
    int high = sizeNum - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 2);
        if (nums[mid] == target) return mid;

        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && nums[mid] > target) {
                return binarySearch(nums, target, low, mid);
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] <= target && nums[high] > target) {
                return binarySearch(nums, target, mid, high);
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int binarySearch(int nums[], int target, int low, int high) {

    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        }
    }
    return -1;
}



int main() {

    int t1[] = {7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
    int len = 10;
    int i;
    int index = -1;
    for (i = -1; i < 11; i++) {
        index = search(t1, i, len);
        printf("Find %d at index %d\n", i, index);
    }
}