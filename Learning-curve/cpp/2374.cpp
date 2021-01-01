#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
LinkList DeleteMin(LinkList &L) {
    // 删除带头结点的单链表L中的最小值结点（最小值唯一）(扫描)
    LNode *p = L->next, *pre = L;    // p为工作指针，pre指向其前驱
    LNode *minp = p, *minpre = pre;  // 保存最小值结点及其前驱
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}
LinkList DeleteMin1(LinkList &L) {
    // 删除不带头结点的单链表L中的最小值结点（最小值唯一）
    LNode *p = L->next, *pre = L, *q;
    LNode *minp = pre, *minpre = pre;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    if (minpre == minp) {  // 第一个结点为最小值结点
        q = L;
        L = L->next;
        free(q);
    } else {
        minpre->next = minp->next;
        free(minp);
    }
    return L;
}
int main() {
    LinkList L;
    LNode *head;
    L = (LinkList)malloc(sizeof(LNode));
    head = L;
    for (int i = 0; i < 5; i++) {
        LinkList temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        L->next = temp;
        L = L->next;
    }
    // 不带头结点
    L = head->next;
    L = DeleteMin1(L);
    while (L != NULL) {
        cout << L->data << endl;
        L = L->next;
    }

    // 带头结点
    // L = DeleteMin(head);
    // while (head->next != NULL) {
    //     head = head->next;
    //     cout << head->data << endl;
    // }
    return 0;
}