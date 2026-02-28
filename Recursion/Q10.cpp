//Fibonacci Series using recursion
#include<iostream>
using namespace std;
int fibo(int n){
    if(n == 1)return 0;
    if(n == 2)return 1;
    return fibo(n-1) + fibo(n-2);
}
int main(){
    int n,ans;
    cout<<"Enter no: ";
    cin>>n;
    ans = fibo(n);
    cout<<"Ans is: "<<ans;
}