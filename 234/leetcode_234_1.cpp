#include <iostream>
using namespace std;
#define ErrorFlag -1

class Node {
    public:
        int data;
        Node *next;
    Node(int da = 0, Node* p = NULL) {
        this->data = da;
        this->next = p;
    }
};

class List {
    private:
        Node *head, *tail;
        int position;
    public:
        List () { head = tail = NULL; };
        ~List() {
            delete head;
            delete tail;
        };
        void insert(int da);
        int search(int da);
        void del(int da);
        void reverse();
        void print();
        bool isPalindrome();
};

void List::insert(int da)
{
    if (head == NULL) {
        head = tail = new Node(da);
        head->next = NULL;
        tail->next = NULL;
    } else {
        Node *p = new Node(da);
        tail->next = p;
        tail = p;
        tail->next = NULL;
    }
    cout << da << ": 数据插入成功" << endl;
}

int List::search(int da)
{
    Node *h = head;
    if (h == NULL) {
        cout << "头节点不能为空";
        return ErrorFlag;
    }

    int couter = 0;
    while (h != NULL && h->data != da) {
        h = h->next;
        couter++;
    }

    return couter;
}

void List::del(int da)
{
    Node *p = head, *q = head;
    if (p == NULL) {
        cout << "头节点不能为空" << endl;
        return;
    }

    while(p != NULL && p->data != da) {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    cout << da << ": 删除成功 " << endl;
}

void List::reverse() 
{
    // 反转指针
    Node *pNode = head; // 当前节点
    Node *pPrev = NULL; // 当前节点的上一个节点
    Node *pNext = NULL; // 当前节点的下一个节点
    Node *preReverseHead = NULL;    // 新链表的头指针


    while(pNode != NULL) {
        pNext = pNode->next;    // 建立链接
        if (pNext == NULL) {    // 判断pNode 是否是最后一个节点
            preReverseHead = pNode;
        }
        pNode->next = pPrev;   // 指针反转
        pPrev = pNode;
        pNode = pNext;
    }

    tail = head;
    head = preReverseHead;
    cout << "reverse success" << endl;
}

void List::print()
{
    Node *p = head;
    while (p != NULL) {
        cout << p->data << " \a";
        p = p->next;
    }
    cout << endl;
}

/**
 * 1. 使用快慢两个指针找到链表中点，慢指针每次前进一步，快指针每次前进两步
 * 2. 在慢指针前进的过程中，同时修改其next指针，使得链表前半部分反序
 * 3. 最后比较中点两侧链表是否相等
 */
bool List::isPalindrome()
{
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node *slow = head, *fast = head, *prev = NULL;
    while(fast) {   // find mid node
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }

    while(slow) { // reverse
        Node *ovn = slow->next;
        slow->next = prev;
        prev = slow;
        slow = ovn;
    }

    while(head && prev) {   // check
        if (head->data != prev->data) {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}

void test_1() {   
    int pos;
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    pos = l.search(5);
    cout << "search: 5, pos: " <<  (pos == ErrorFlag ? ErrorFlag : pos ) << endl;
    l.print();
    l.del(5);
    l.del(3);
    l.reverse();
    l.insert(6);
    l.insert(7);
    l.print();
}

void test_2() {
    List l;
    int n[] = {1, 2, 3, 5, 3, 2, 1};

    for (int i = 0; i < 7; i++) {
        l.insert(n[i]);
    }
    l.print();

    if (l.isPalindrome()) {
        cout << "是回文字符串" << endl;
    } else {
        cout << "不是回文字符串" << endl;
    }
}

int main ()
{
   test_2(); 

   return 0;
}