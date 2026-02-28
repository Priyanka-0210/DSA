//Power function - a^b using recursion
#include<iostream>
using namespace std;
int power(int a, int b);
int main(){
    int a,b,ans;
    cout<<"Enter no: ";
    cin>>a>>b;
    ans = power(a,b);
    cout<<"Ans is: "<<ans;
}
int power(int a, int b){
    if(b == 0)return 1;
    return power(a,b-1) * a;
}