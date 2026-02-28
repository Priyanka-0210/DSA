//factorial using recursion
#include<iostream>
using namespace std;
int fact(int n){
    if(n<=1){
        return 1;
    }
    else return fact(n-1) * n;
}
int main(){
    int n,ans;
    cout<<"Enter n: ";
    cin>>n;
    ans = fact(n);
    cout<<ans;
}