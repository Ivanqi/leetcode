#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insert(struct ListNode *node, int val) {
    struct ListNode *newNode = NULL;
    newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = node;
    node = newNode;

    return node;
}

struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL) return head;
    struct ListNode *p = head;   // 输入元素
    struct ListNode *q = head;   // 插入记录
    struct ListNode *k = q;      // 记录q前一个指针，修改指针时使用

    while(p->next != NULL) {
        if (p->val < p->next->val) { // 若原本的大小顺序不用变
            p = p->next;
            continue;
        }

        // 找到合适的插入位置q
        if (p->next->val < q->val) {
            struct ListNode *temp = p->next;
            p->next = temp->next;
            temp->next = q;

            if (q == head) {
                head = temp;
            } else {
                k->next = temp;
            }
            q = head;               // 从头开始检索
        } else {
            if (q == p) {
                p = p->next;
                continue;
            } else {
                k = q;
                q = q->next;
            }
        }
    }
    return head;
}

void print(struct ListNode *node){
    if (node == NULL) {
        exit(1);
    }
    struct ListNode *p = node;
    while(p != NULL) {
        printf("Node val: %d\n", p->val);
        p = p->next;
    }
}

void test_case_1() {
    struct ListNode *n = NULL;
    int arr[] = {4, 2, 1, 3};
    int i;
    for (i = 0; i < 4; i++) {
        n = insert(n, arr[i]);
    }
    print(n);
    struct ListNode *res = insertionSortList(n);
    printf("\n --------- \n");
    print(res);
}

void test_case_2() {
    struct ListNode *n = NULL;
    int arr[] = {-1, 5, 3, 4, 0};
    int i;
    for (i = 0; i < 5; i++) {
        n = insert(n, arr[i]);
    }
    print(n);
    struct ListNode *res = insertionSortList(n);
    printf("\n --------- \n");
    print(res);
}

int main() {

    test_case_2();
    return 0;
}