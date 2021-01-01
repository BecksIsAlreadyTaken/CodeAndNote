#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
} Stack;
void initStack(Stack &s) { s.top = -1; }
bool isEmpty(Stack s) {
    if (s.top == -1) return 1;
    return 0;
}
bool push(Stack &s, ElemType x) {
    if (s.top == MAXSIZE - 1) return 0;
    s.data[++s.top] = x;
    return 1;
}
bool pop(Stack &s, ElemType &x) {
    if (s.top == -1) return 0;
    x = s.data[s.top--];
    return 1;
}
bool getTop(Stack s, ElemType &x) {
    if (s.top == -1) return 0;
    x = s.data[s.top];
    return 1;
}
Stack s;
bool matchBrackets(char *str) {
    initStack(s);
    int i = 0;
    int x;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
                push(s, '(');
                break;
            case '[':
                push(s, '[');
                break;
            case '{':
                push(s, '{');
                break;
            case ')':
                pop(s, x);
                if (x != '(') return 0;
                break;
            case ']':
                pop(s, x);
                if (x != '[') return 0;
                break;
            case '}':
                pop(s, x);
                if (x != '{') return 0;
                break;
            default:
                break;
        }
        i++;
    }
    if (!isEmpty(s)) return 0;
    return 1;
}
void arrangeTrain(char *str) {
    char *p = str, *q = str;
    int c;
    initStack(s);
    while (*p != '\0') {
        if (*p == 'H')
            push(s, *p);
        else
            *(q++) = *p;
        p++;
    }
    while (!isEmpty(s)) {
        pop(s, c);
        *(q++) = c;
    }
}
double p(int n, double x) {
    struct s {
        int no;
        double val;
    } st[MAXSIZE];
    int top = -1, i;
    double fv1 = 1, fv2 = 2 * x;
    for (i = n; i >= 2; i--) {
        top++;
        st[top].no = i;
    }
    while (top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0) return fv1;
    return fv2;
}
int main() {
    // char str[10] = {'1', '*', '(', '2', '+', '3', ')', '{', '}', '['};
    // cout << matchBrackets(str) << endl;
    /*------------------------------------------*/
    char train[5] = {'H', 'S', 'H', 'H', 'S'};
    arrangeTrain(train);
    for (int i = 0; i < 5; i++) {
        cout << train[i] << endl;
    }
    /*------------------------------------------*/
    cout << p(2, 1) << endl;
    return 0;
}