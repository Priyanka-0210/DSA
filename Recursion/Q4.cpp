//Number divided by 2
#include<iostream>
using namespace std;
float func(int a, int b){
    if(a == 0) return 0;
    return func(a-1,2) + 0.5;
}
int main(){
    float ans;
    ans = func(19,2);
    cout<<ans;
}