//Optimized way of solving Power function - a^b
#include<iostream>
using namespace std;
int Optimizedpower(int a,int b){
    if(b == 0) return 1;
    if((b % 2)!= 0){
        int temp = Optimizedpower(a,b/2);
        int power = temp * temp;
        return a * power;
    }
    else{
        int temp = Optimizedpower(a,b/2);
        int power = temp * temp;
        return power;
    }
}
int main(){
    int a,b,ans;
    cout<<"Enter no: ";
    cin>>a>>b;
    ans = Optimizedpower(a,b);
    cout<<"Ans is: "<<ans;
}