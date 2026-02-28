//Optimized way of solving Power function - a^b
#include<bits/stdc++.h>
using namespace std;
int OptimizedPower(int a, int b){
    if(b == 0) return 1;
    if((b%2) != 0){
        return pow(OptimizedPower(a,b/2),2) * a;
    }
    else{
        return pow(OptimizedPower(a,b/2),2);
    }
}
int main(){
    int a,b,ans;
    cout<<"Enter no: ";
    cin>>a>>b;
    ans = OptimizedPower(a,b);
    cout<<"Ans is: "<<ans;
}