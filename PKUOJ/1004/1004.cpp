#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    double output = 0;
    for(int i=12;i>0;i--){
        double t;
        cin>>t;
        output+=t;
    }
    cout<<"$"<<output/12.0<<setprecision(2)<<endl;
    return 0;
}