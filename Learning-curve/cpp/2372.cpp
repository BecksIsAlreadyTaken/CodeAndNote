#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
void del_x(LinkList &L, int x) {
    // 删除带头结点的单链表L中所有值为x的结点
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
    L->next = NULL;
    del_x(head, 3);
    while (head->next != NULL) {
        head = head->next;
        cout << head->data << endl;
    }
    return 0;
}