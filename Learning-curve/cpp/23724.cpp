#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LNode *FindLoopStartingPoint(LinkList L) {
    LNode *fast = L, *slow = L;
    while (slow != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (slow == NULL || fast->next == NULL) return NULL;
    LNode *p1 = L, *p2 = slow;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}
int main() {
    LinkList L;
    LNode *head, *p;
    L = (LinkList)malloc(sizeof(LNode));
    head = L;
    for (int i = 0; i < 16; i++) {
        LinkList temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        L->next = temp;
        L = L->next;
    }
    p = head;
    for (int i = 0; i < 5; i++) p = p->next;
    L->next = p;
    L = head;
    p = FindLoopStartingPoint(L);
    cout << p->data << endl;
    return 0;
}