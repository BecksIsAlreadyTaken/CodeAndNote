#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
void del_x1(LinkList &L, int x) {
    // 删除不带头结点的单链表L中所有值为x的结点（递归）
    LNode *p;
    if (L == NULL) return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        del_x1(L, x);
    } else
        del_x1(L->next, x);
}
void del_x2(LinkList &L, int x) {
    // 删除不带头结点的单链表L中所有值为x的结点（从头至尾扫描）
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
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
    L = head->next;
    // del_x1(L, 3);
    // del_x2(L, 3);
    while (L != NULL) {
        cout << L->data << endl;
        L = L->next;
    }
    return 0;
}