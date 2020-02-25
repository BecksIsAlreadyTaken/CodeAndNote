#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
int translate(char c)
{
    switch (c)
    {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
        return 9;
    default:
        return -1;
    }
}
void findAndReplaceAll(string &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (translate(data[i]) != -1)
        {
            data[i] = translate(data[i]) + '0';
        }
    }
}
int main()
{
    int n = 0;
    string str;
    cin >> n;
    vector<string> v;
    while (n--)
    {
        cin >> str;
        // remove hyphens
        str.erase(remove(str.begin(), str.end(), '-'), str.end());
        // translate to standard form based on the map
        findAndReplaceAll(str);
        str.insert(3, "-");
        v.push_back(str);
    }
    // sort(v.begin(), v.end()); // the problem request to sort but it takes too much time so i didnt
    // find duplicates
    map<string, int> dup;
    for (int i = 0; i < v.size(); i++)
    {
        ++dup[v[i]];
    }
    // check if there are duplicates
    bool flag = false;

    for (map<string, int>::iterator it = dup.begin(); it != dup.end(); it++)
    {
        if (it->second > 1)
        {
            cout << it->first << " " << it->second << endl;
            flag = true;
        }
    }
    if (!flag)
        cout << "No duplicates." << endl;
    return 0;
}