//dividing n by m
#include<iostream>
using namespace std;
float func(int n, int m){
    if(n > m){
        if(n == 1) return 1;
        return func(n-m,m) + 1;
    }
    else{
        return (float)n/m;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    float ans;
    ans = func(n,m);
    cout<<ans;
}