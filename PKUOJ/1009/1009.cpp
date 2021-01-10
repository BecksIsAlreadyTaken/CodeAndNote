#include <algorithm>
#include <iostream>
using namespace std;
int input[1000][2];
int width, arg1, arg2;
int cnt, length;
struct node {
    int index;
    int value;
} output[8000];
int absolute(int a) { return a > 0 ? a : -a; };
int compareIndex(node a, node b) { return a.index < b.index; }
int getArg(int index) {
    int i = 0;
    int c = 0;
    while (i < index) i += input[c++][1];
    return input[c - 1][0];
}
int getMax(int index) {
    int arg1 = getArg(index);
    int max = 0;
    int row = (index - 1) / width;
    int column = (index - 1) % width;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            int pos = i * width + j;
            if (i < 0 || j < 0 || j >= width || pos >= length ||
                pos == index - 1)
                continue;
            int arg = getArg(pos + 1);
            if (absolute(arg - arg1) > max) max = absolute(arg - arg1);
        }
    }
    return max;
}
int main() {
    do {
        cin >> width;
        cnt = 0;
        length = 0;
        do {
            cin >> arg1 >> arg2;
            input[cnt][0] = arg1;
            input[cnt][1] = arg2;
            cnt++;
            length += arg2;
        } while (arg1 != 0 && arg2 != 0);
        cout << width << endl;
        int pos = 1, k = 0;
        for (int c = 0; c <= cnt; c++) {
            int row = (pos - 1) / width;
            int col = (pos - 1) % width;
            for (int i = row - 1; i <= row + 1; i++)
                for (int j = col - 1; j <= col + 1; j++) {
                    int p = i * width + j;
                    if (i < 0 || j < 0 || j >= width || p >= length) continue;
                    output[k].index = p + 1;
                    output[k++].value = getMax(p + 1);
                }
            pos += input[c][1];  //跳跃到下一连续段起始点
        }
        sort(output, output + k, compareIndex);
        node temp = output[0];
        for (int i = 0; i < k; i++) {
            if (output[i].value == temp.value) continue;
            cout << temp.value << " " << output[i].index - temp.index << endl;
            temp = output[i];
        }
        cout << temp.value << " " << length - temp.index + 1 << endl;
        cout << 0 << " " << 0 << endl;
    } while (width != 0);
    cout << 0 << endl;
    return 0;
}