#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
int length(LinkList L) {
    int len = 0;
    while (L->next != NULL) {
        len++;
        L = L->next;
    }
    return len;
}
LinkList find_addr(LinkList A, LinkList B) {
    int m, n;
    m = length(A);
    n = length(B);
    LNode *p, *q;
    for (p = A; m > n; m--) {
        p = p->next;
    }
    for (q = B; n > m; n--) q = q->next;
    while (p->next != NULL && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}
int main() {
    LinkList A, B;
    LNode *ahead, *bhead;
    A = (LinkList)malloc(sizeof(LNode));
    B = (LinkList)malloc(sizeof(LNode));
    ahead = A;
    bhead = B;
    for (int i = 0; i < 2; i++) {
        LinkList tempA = (LinkList)malloc(sizeof(LNode));
        tempA->data = i;
        A->next = tempA;
        A = A->next;
    }
    for (int i = 2; i < 5; i++) {
        LinkList tempB = (LinkList)malloc(sizeof(LNode));
        tempB->data = i;
        A->next = tempB;
        A = A->next;
        B->next = tempB;
        B = B->next;
    }
    A = ahead;
    B = bhead;
    LNode *p = find_addr(A, B);
    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }
    return 0;
}