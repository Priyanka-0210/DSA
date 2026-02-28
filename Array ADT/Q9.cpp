//Find the minimum no of merge operations to make a given array palindrome
#include<iostream>
using namespace std;
int merge(int Arr[], int size){
    int i=0,j=size-1,count = 0;
    while(i<j){
        if(Arr[i] < Arr[j]){
            Arr[i+1] += Arr[i];
            count++;
            i++;
        }
        else if(Arr[i] > Arr[j]){
            Arr[j-1] += Arr[j];
            count++;
            j--;
        }
        else{
            i++;
            j--;
        }
    }
    return count;
}
int main(){
    int Arr[] = {6,1,4,3,1,7};
    int size = sizeof(Arr)/sizeof(Arr[0]);
    int ans = merge(Arr,size);
    cout<<"Ans: "<<ans;
}