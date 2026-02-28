//Counting digits in a number using recursion
#include<iostream>
using namespace std;
int count(int n, int coun){
    coun++;
    if( n < 10) return coun;
    n = n / 10;
    return count(n,coun);
}
int main(){
    int n, coun = 0, ans;
    cout<<"Enter n: ";//444
    cin>>n;
    ans = count(n,coun);
    cout<<ans;
}