#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define size 1100
struct node {
    int index;
    int value;
} output[size * 8];
int input[size][2];  // store input arg
int width;
int length;  // total pixel count
int cnt;     // total pair count
int cmp(node, node);
int computeMax(int);
int main() {
    while (scanf("%d", &width) && width > 0) {
        length = 0;
        cnt = 0;
        int v, c;
        while (scanf("%d%d", &v, &c) && c > 0) {  // collect input arg
            input[cnt][0] = v;
            input[cnt][1] = c;
            cnt++;
            length += c;
        }
        printf("%d\n", width);
        int i = 0, l = 0;
        for (int c = 0; c <= cnt;
             c++) {  // 枚举每个连续段的起始点和终止点周围的8个
            int row = i / width;
            int column = i % width;
            for (int j = row - 1; j <= row + 1; j++) {
                for (int k = column - 1; k <= column + 1; k++) {
                    int tempi = j * width + k;
                    if (j < 0 || k < 0 || k >= width || tempi >= length)
                        continue;
                    output[l].index = tempi;
                    output[l].value = computeMax(tempi);
                    l++;
                }
            }
            i += input[c][1];
        }
        sort(output, output + l, cmp);
        node temp = output[0];
        for (int i = 0; i < l; i++) {
            if (output[i].value == temp.value) continue;
            printf("%d %d\n", temp.value, output[i].index - temp.index);
            temp = output[i];
        }
        printf("%d %d\n", temp.value, length - temp.index);
        printf("0 0\n");
    }
    printf("0\n");
    return 0;
}
int cmp(node a, node b) { return a.index < b.index; }
int getValue(int index) {
    int i = 0, j = 0;
    while (j <= index) j += input[i++][1];
    return input[i - 1][0];
}
int computeMax(int index) {
    int row = index / width;
    int column = index % width;
    int max = 0, self = getValue(index);
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            int tempi = i * width + j;
            if (i < 0 || j < 0 || j >= width || tempi >= length ||
                tempi == index)
                continue;
            int temp = getValue(tempi);
            if (abs(temp - self) > max) max = abs(temp - self);
        }
    }
    return max;
}