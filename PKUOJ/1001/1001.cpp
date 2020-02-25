#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string multi(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> v(a.size() + b.size(), 0);
    string result = "";
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            v[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= 10)
        {
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
    }
    for (int i = v.size() - 1; i > 0 && v[i] == 0; i--)
    {
        v.erase(v.end() - 1);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        result += (char)(v[i] + '0');
    }
    return result;
}
string power(double r, int n)
{
    ostringstream os;
    os << r;
    string r_str = os.str();
    vector<char> vec(r_str.begin(), r_str.end());
    int place = 0; //decimal place
    bool flag = false;
    // check if it is an integer, if not, save the decimal place.
    vector<char>::iterator it = find(vec.begin(), vec.end(), '.');
    if (it == vec.end())
    {
        // integer
        // do nothing
    }
    else
    {
        // save the place
        place = vec.end() - it - 1;
        //remove the decimal
        vec.erase(it);
        // remove the former zeros
        flag = false;
        for (int i = 0; !flag;)
        {
            switch (vec[i])
            {
            case '0':
                vec.erase(vec.begin());
                continue;
            default:
                flag = true;
                break;
            }
        }
    }
    // do the math
    string result = "1";
    for (int i = 0; i < n; i++)
    {
        result = multi(result, string(vec.begin(), vec.end()));
    }
    // calculate the final place of decimal
    place = place * n;
    if (place > result.size())
    {
        // add back the zeros
        for (int diff = place - result.size(); diff >= 1; diff--)
        {
            result.insert(result.begin(), '0');
        }
    }
    if (place == 0)
    {
        // integer
        // do nothing
    }
    else
    {
        // insert decimal
        result.insert(result.end() - place, '.');
    }
    return result;
}
int main()
{
    double r;
    int n;
    while (cin >> r >> n)
    {
        cout << power(r, n) << endl;
    }
    return 0;
}
