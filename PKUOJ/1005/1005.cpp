#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    double x,y;
    cin>>n;
    vector<int> output;
    while(n--){
        cin>>x>>y;
        output.push_back(ceil((x*x+y*y)*1.57/50.0));
    }
    for(int i=0;i<output.size();i++){
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<output[i]<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}