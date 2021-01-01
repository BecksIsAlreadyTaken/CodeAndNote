#include <iostream>
using namespace std;
typedef struct Node {
    int data;
    struct Node* next;
} Node;
void change_list(Node* h) {
    Node *p, *q, *r, *s;
    p = q = h;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
        if (q->next != NULL) q = q->next;
    }
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }
    s = h->next;
    q = p->next;
    p->next = NULL;
    while (q != NULL) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}
int main() {
    Node* L;
    Node *head, *p;
    L = (Node*)malloc(sizeof(Node));
    head = L;
    head->data = -1;
    for (int i = 0; i < 9; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = i;
        L->next = temp;
        L = L->next;
    }
    for (int i = 8; i >= 0; i--) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = i;
        L->next = temp;
        L = L->next;
    }
    L = head;
    while (head->next != NULL) {
        head = head->next;
        cout << head->data << endl;
    }
    cout << "------------------" << endl;
    change_list(L);
    while (L->next != NULL) {
        L = L->next;
        cout << L->data << endl;
    }
    return 0;
}
