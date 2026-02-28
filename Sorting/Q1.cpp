//Bubble Sort
#include<iostream>
using namespace std;

//here n = Arr.size()
void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

void swapdata(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//here n = Arr.size()
void BubbleSort(int Arr[], int n){
    bool check;
    for(int i = 0; i < n-1; i++){
        check = false;
        for(int j = 0; j < n-1-i; j++){
            if(Arr[j] > Arr[j+1]){
                swapdata(&Arr[j],&Arr[j+1]);
                check = true;
            }
            if(check == false) break;
        }
    }
}

int main(){
    int Arr[] = {32, -5, 1, 12, 300, 6, 87, 10};
    BubbleSort(Arr,8);
    Display(Arr,8);
    return 0;
}