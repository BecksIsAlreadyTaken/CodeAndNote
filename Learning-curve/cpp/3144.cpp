#include <iostream>
using namespace std;
typedef char ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;
bool check(LinkList L, int n) {
    int i;
    char s[n / 2];
    LNode* p = L;
    for (i = 0; i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1) p = p->next;
    while (p != NULL && s[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == -1) return 1;
    return 0;
}
int main() {
    LinkList L;
    LNode* head;
    L = (LinkList)malloc(sizeof(LNode));
    head = L;
    for (int i = 0; i < 7; i++) {
        LinkList temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i % 2;
        L->next = temp;
        L = L->next;
    }
    L = head->next;
    cout << check(L, 7) << endl;
    return 0;
}