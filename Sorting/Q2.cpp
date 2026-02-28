//Insertion Sort
#include<iostream>
using namespace std;

//here n = Arr.size()
void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

//here n = Arr.size()
void InsertSort(int Arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int x = Arr[i];
        while(j >= 0 && Arr[j] > x){
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = x;
    }
}

int main(){
    int Arr[] = {32, -15, 11, 12, 390, -6, 8, 190};
    InsertSort(Arr,8);
    Display(Arr,8);
    return 0;
}