#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
int Pattern(LinkList A, LinkList B) {
    LNode *p = A;
    LNode *pre = p;
    LNode *q = B;
    while (p && q) {
        if (p->data == q->data) {
            p = p->next;
            q = q->next;
        } else {
            pre = p->next;
            p = pre;
            q = B;
        }
    }
    if (q == NULL) return 1;
    return 0;
}
int main() {
    LinkList A, B;
    LNode *ahead, *bhead;
    A = (LinkList)malloc(sizeof(LNode));
    B = (LinkList)malloc(sizeof(LNode));
    ahead = A;
    bhead = B;
    for (int i = 0; i < 5; i++) {
        LinkList tempA = (LinkList)malloc(sizeof(LNode));
        tempA->data = i;
        A->next = tempA;
        A = A->next;
    }
    for (int i = 0; i < 4; i++) {
        LinkList tempB = (LinkList)malloc(sizeof(LNode));
        tempB->data = i;
        B->next = tempB;
        B = B->next;
    }
    A = ahead->next;
    B = bhead->next;
    cout << Pattern(A, B) << endl;
    return 0;
}