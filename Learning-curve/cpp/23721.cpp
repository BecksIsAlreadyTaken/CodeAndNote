#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *link;
} LNode, *LinkList;
int Search_k(LinkList list, int k) {
    LNode *p = list->link, *q = list->link;
    int count = 0;
    while (p != NULL) {
        if (count < k)
            count++;
        else
            q = q->link;
        p = p->link;
    }
    if (count < k) return 0;
    cout << q->data << endl;
    return 1;
}
int main() {
    LinkList L;
    LNode *head;
    L = (LinkList)malloc(sizeof(LNode));
    head = L;
    for (int i = 0; i < 5; i++) {
        LinkList temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        L->link = temp;
        L = L->link;
    }
    L = head;
    for (int i = 1; i < 5; i++) {
        Search_k(L, i);
    }
    return 0;
}