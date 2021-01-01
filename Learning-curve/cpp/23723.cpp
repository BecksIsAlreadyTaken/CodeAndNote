#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
void func(LinkList &L, int n) {
    LNode *p = L, *r;
    int *q, m;
    q = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) *(q + i) = 0;
    while (p->next != NULL) {
        m = p->next->data > 0 ? p->next->data : -p->next->data;
        if (*(q + m) == 0) {
            *(q + m) = 1;
            p = p->next;
        } else {
            r = p->next;
            p->next = r->next;
            free(r);
        }
    }
    free(q);
}
int main() {
    LinkList L;
    LNode *head;
    L = (LinkList)malloc(sizeof(LNode));
    head = L;
    for (int i = 0; i < 7; i++) {
        LinkList temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i - 3;
        L->next = temp;
        L = L->next;
    }
    L = head;
    func(L, 3);
    while (L->next != NULL) {
        L = L->next;
        cout << L->data << endl;
    }
    return 0;
}