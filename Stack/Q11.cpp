//Tower of Hanoi
#include<iostream>
#include<math.h>
using namespace std;
void TOH(int A,int C,int B,int n){
    if(n == 1){
        cout<<A<<" -> "<<C<<endl;
    }
    else{
        TOH(A,B,C,n-1);
        cout<<A<<" -> "<<C<<endl;
        TOH(B,C,A,n-1);
    }
}

int main(){
    TOH(1,3,2,3);
    int n = pow(2,3) - 1;
    cout<<"No of moves: "<<n<<endl;
    return 0;
}