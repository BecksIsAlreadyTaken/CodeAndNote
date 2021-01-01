#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;
void ReversePrint(LinkList &L) {
    // 从尾到头输出带头结点的单链表L每个结点的值
    if (L->next != NULL) {
        ReversePrint(L->next);
    }
    if (L != NULL) cout << L->data << endl;
}
int main() {
    LinkList L;
    LNode *head;
    L = (LinkList)malloc(sizeof(LNode));
    head = L;
    for (int i = 0; i < 5; i++) {
        LNode *temp = (LinkList)malloc(sizeof(LNode));
        temp->data = i;
        L->next = temp;
        L = L->next;
    }
    ReversePrint(
        head->next);  // ??Question:
                      // 带头结点的单链表，传入参数是head还是head->next?
    return 0;
}