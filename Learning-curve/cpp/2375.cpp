#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
void Reverse1(LinkList &L) {
    // 将带头结点的单链表就地逆置（头插法）
    LNode *p, *n;  // n为p的后继，防止断链
    p = L->next;
    L->next = NULL;  // 摘下头结点
    while (p != NULL) {
        n = p->next;
        p->next = L->next;
        L->next = p;
        p = n;
    }
}
void Reverse2(LinkList &L) {
    // 遍历单链表L，并将结点指针反转
    LNode *pre, *p = L->next, *n = p->next;
    p->next = NULL;  // 第一个结点，也是逆置后的最后一个结点，将其next域置为NULL
    while (n != NULL) {
        pre = p;
        p = n;
        n = n->next;
        p->next = pre;
    }
    L->next = p;  // 最后一个结点，也是逆置后的第一个结点，将头结点加在前面
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
    L = head;
    Reverse1(L);
    Reverse2(L);
    while (L->next != NULL) {
        L = L->next;
        cout << L->data << endl;
    }
    return 0;
}