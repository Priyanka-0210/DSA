//Find HCF of two numbers using recursion
#include<iostream>
using namespace std;
int GCD(int n, int m){
    if(n == m) return n;
    if(n < m){
        return GCD(n,m-n);      
    }
    else{
        return GCD(n-m,m);
    }
}
int alternateGCD(int n, int m){
    if(m != 0){
        return alternateGCD(m,n%m);
    }
    return n;
}
int main(){
    int n,m,ans,alternateans;
    cout<<"Enter no: ";
    cin>>n>>m;
    ans = GCD(n,m);
    cout<<"GCD of: "<<ans<<endl;
    alternateans = alternateGCD(n,m);
    cout<<"alternateGCD of: "<<alternateans;
}