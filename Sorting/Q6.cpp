//Shell sort OR Diminishing Incremental Sort
#include<iostream>
using namespace std;

void ShellSort(int Arr[], int n){
    for(int i = n/2; i >= 1; i = i/2){
        for(int j = i; j < n; j++){
            int temp = Arr[j];
            int k = j - i;
            while(k >= 0 && Arr[k] > temp){
                Arr[k+i] = Arr[k];
                k = k - i;
            }
            Arr[k+i] = temp;
        }
    }
}

void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
}

int main(){
    int Arr[] = {2,5,7,-3,3,8,1,0,6};
    cout<<"Before sorting: ";
    Display(Arr,9);
    ShellSort(Arr,9);
    cout<<endl;
    cout<<"After sorting: ";
    Display(Arr,9);
}