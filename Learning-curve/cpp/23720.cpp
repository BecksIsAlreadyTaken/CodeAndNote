#include <iostream>
using namespace std;
typedef struct DNode {
    int data;
    struct DNode *prior, *next;
    int freq;
} DNode, *DLinkList;
DLinkList Locate(DLinkList &L, int x) {
    DNode *p = L->next, *q;
    while (p && p->data != x) {
        p = p->next;
    }
    if (!p) return NULL;
    p->freq++;
    if (p->next != NULL) p->next->prior = p->prior;
    p->prior->next = p->next;
    q = p->prior;
    while (q != L && q->freq <= p->freq) {
        q = q->prior;
    }
    p->next = q->next;
    q->next->prior = p;
    p->prior = q;
    q->next = p;
    return p;
}
int main() {
    DLinkList L;
    L = (DLinkList)malloc(sizeof(DNode));
    L->next = L;
    L->prior = L;
    DNode *head = L;
    for (int i = 0; i < 5; i++) {
        DNode *temp = (DNode *)malloc(sizeof(DNode));
        temp->data = i;
        temp->freq = i + 1;
        L->next = temp;
        temp->prior = L;
        L = L->next;
    }
    L = head;
    while (head != NULL) {
        cout << head->data << "\t" << head->freq << endl;
        head = head->next;
    }
    cout << "------------------------------" << endl;
    for (int i = 4; i > 0; i--) {
        Locate(L, i);
        head = L;
        while (head != NULL) {
            cout << head->data << "\t" << head->freq << endl;
            head = head->next;
        }
        cout << "------------------------------" << endl;
    }
    return 0;
}