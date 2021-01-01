#include <iostream>
using namespace std;
int judge(char A[]) {
    // 判断操作序列A是否合法
    int i, j, k;
    i = j = k = 0;
    while (A[i] != '\0') {
        switch (A[i]) {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if (k > j) {
                    return 0;
                }
        }
        i++;
    }
    if (j != k) {
        return 0;
    }
    return 1;
}
int main() {
    char A[10] = {'I', 'O', 'I', 'I', 'O', 'O', 'I', 'I', 'O', 'O'};
    cout << judge(A) << endl;
    return 0;
}