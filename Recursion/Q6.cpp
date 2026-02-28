//Sum of two numbers using recursion
#include<iostream>
using namespace std;
int func(int a, int b);
int main(){
    int a,b,ans;
    cout<<"Enter no: ";
    cin>>a>>b;
    ans = func(a,b);
    cout<<"Sum is: "<<ans<<endl;
}
int func(int a, int b){
    if(a == 0)return b;
    if(b == 0)return a;
    return func(a,b-1) + 1;
}