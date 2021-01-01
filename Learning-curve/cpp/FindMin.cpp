#include <iostream>
using namespace std;
int findMin(int A[], int n) {
    int i, B[n] = {};
    for (i = 0; i < n; i++)
        if (A[i] > 0 && A[i] <= n) B[A[i] - 1] = 1;
    for (i = 0; i < n; i++)
        if (B[i] == 0) break;
    return i + 1;
}
int main() {
    int n = 3;
    int A[n] = {-1, -2, 3};
    cout << findMin(A, n) << endl;
    return 0;
}