#include <string.h>

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
char haab[19][20] = {"pop",  "no",   "zip",   "zotz",  "tzec", "xul", "yoxkin",
                     "mol",  "chen", "yax",   "zac",   "ceh",  "mac", "kankin",
                     "muan", "pax",  "koyab", "cumhu", "uayet"};
char tzolkin[20][10] = {"imix",  "ik",    "akbal", "kan",   "chicchan",
                        "cimi",  "manik", "lamat", "muluk", "ok",
                        "chuen", "eb",    "ben",   "ix",    "mem",
                        "cib",   "caban", "eznab", "canac", "ahau"};
int main() {
    int n;
    cin >> n;
    vector<string> s;
    cout << n << endl;
    while (n--) {
        int j = 0;
        int d, m, y;
        char temp[10];
        scanf("%d. %s %d", &d, temp, &y);
        for (int i = 0; i < 19; i++) {
            if (strcmp(haab[i], temp) == 0) {
                m = i + 1;
                break;
            }
        }
        int total = y * 365 + (m - 1) * 20 + d;
        int ynumber = total / 260;
        int mnumber = (total % 260) % 13 + 1;
        string t1, t2;
        stringstream ss1, ss2;
        ss1 << mnumber;
        ss1 >> t1;
        ss2 << ynumber;
        ss2 >> t2;
        string output = t1 + " " + tzolkin[(total % 260) % 20] + " " + t2;
        s.push_back(output);
    }
    for (int i = 0; i < s.size(); i++) cout << s[i] << endl;
    return 0;
}