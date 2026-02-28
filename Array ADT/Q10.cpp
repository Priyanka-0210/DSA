//Print all sub-Arrays with a zero-sum in a given array
#include<iostream>
using namespace std;
int main(){
    int size = 10;
    int Arr[size] = {3,4,-7,3,1,3,1,-4,-2,-2};
    for(int i=0;i<size;i++){
        int sum = 0;
        for(int j=i;j<size;j++){
            sum += Arr[j];
            if(sum == 0){
                cout<<"Sub-array ["<<i<<" to "<<j<<"]\n";
            }
        }
    }
}
//Time complexity: O(n^2)
//Do dry run of the code to understand better