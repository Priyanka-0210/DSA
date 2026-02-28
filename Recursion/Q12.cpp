//Sum of first n natural numbers
#include<iostream>
using namespace std;
int func(int n, int sum){
    if (n == 0) return sum;
    sum += n;
    return func(n-1,sum);
}
int main(){
    int n,ans, sum = 0;
    cout<<"enter n: ";
    cin>>n;
    ans = func(n,sum);
    cout<<"Ans is: "<<ans;
}