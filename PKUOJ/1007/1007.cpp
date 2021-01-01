#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
bool judge(pair<int, string>, pair<int, string>);
int r;  // inversion number
int n, m;
int main() {
    vector<pair<int, string>> output;
    cin >> n >> m;
    int* seq = new int[n];  // convert string to int[]
    if (n <= 0 || n > 50 || m <= 0 || m > 100) return 0;
    while (m--) {  // input strings
        string temp;
        cin >> temp;
        r = 0;
        for (int i = 0; i < n; i++) seq[i] = temp[i];
        mergeSort(seq, 0, n - 1);
        output.push_back(make_pair(r, temp));
    }
    sort(output.begin(), output.end(), judge);
    for (int i = 0; i < output.size(); i++)
        cout << output[i].second << endl;  // output
    return 0;
}
int* b = new int[n + 1];
void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            r += mid - i + 1;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= high) b[k++] = a[j++];
    for (int i = low; i <= high; i++) a[i] = b[i];
}
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
bool judge(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}