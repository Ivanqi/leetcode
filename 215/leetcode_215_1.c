#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int p, int r) {
    int i, j;
    i = j = p;

    for (; j < r; j++) {
        if (arr[j] >= arr[r]) {
            if (i != j) {
                swap(arr + i, arr + j);
            }
            i++;
        }
    }
    swap(arr + i, arr + j);
    return i;
}

void RS(int *arr, int low, int high, int k) {
    if (low == high) return;
    int i = partition(arr, low, high);
    int temp = i - low; 

    if (temp >= k) {
        RS(arr, low, i - 1, k);   
    } else {
        RS(arr, i + 1, high, k - i);
    }
}


int findKthLargest(int* nums, int numsSize, int k){
    RS(nums, 0, numsSize, k);
    // int i;
    // for(i = 0; i <= numsSize; i++) {
    //     printf("%d\n", nums[i]);
    // }
    return nums[k - 1];
}

void test_case_1() {
    int arr[6] = {3,2,1,5,6,4};
    int k = 2;
	int res = findKthLargest(arr, 5, k);
    printf("结果为：%d \n", res);
}

void test_case_2() {
    int arr[9] = {3,2,3,1,2,4,5,5,6};
    int k = 4;
	int res = findKthLargest(arr, 8, k);
    printf("结果为：%d \n", res);
}

int main() {
    test_case_2();
}