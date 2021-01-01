#include <iostream>
#include <vector>
using namespace std;
int main()
{
    double c;
    vector<int> num;
    while(cin>>c&&c!=0.00){
        double sum = 0;
        int i=1;
        for(;sum<c;i++){
            double temp = i+1;
            sum+=1/temp;
        }
        num.push_back(i-1);
    }
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" card(s)"<<endl;
    }
    return 0;
}