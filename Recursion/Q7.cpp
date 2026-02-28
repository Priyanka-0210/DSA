//Product of two numbers using recursion
#include<iostream>
using namespace std;
int product(int a, int b){
    if(a == 0 || b == 0) return 0;
    return product(a,b-1) + a;
    }
int main(){
    int a,b,ans;
    cout<<"Enter number: ";
    cin>>a>>b;
    ans = product(a,b);
    cout<<"product is: "<<ans;
}