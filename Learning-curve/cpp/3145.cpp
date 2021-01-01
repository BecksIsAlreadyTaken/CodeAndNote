#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType stack[MAXSIZE];
    int top[2];
} stk;
stk s;
int push(int i, ElemType x) {
    if (i < 0 || i > 1) return 0;
    if (s.top[1] - s.top[0] == 1) return 0;
    switch (i) {
        case 0:
            s.stack[++s.top[0]] = x;
            return 1;
        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
    }
}
ElemType pop(int i) {
    if (i < 0 || i > 1) return 0;
    switch (i) {
        case 0:
            if (s.top[0] == -1)
                return -1;
            else
                return s.stack[s.top[0]--];
        case 1:
            if (s.top[1] == MAXSIZE)
                return -1;
            else
                return s.stack[s.top[1]++];
    }
}
int main() {
    for (int i = 0; i < 5; i++) {
        push(0, i);
        push(1, i);
    }
    for (int i = 0; i < 5; i++) {
        cout << pop(0) << "\t" << pop(1) << endl;
    }
    return 0;
}