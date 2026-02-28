//Selection Sort
#include<iostream>
using namespace std;

//here n = Arr.size()
template<class T>
void Display(T Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void swapdata(T *x,T *y){
    T temp = *x;
    *x = *y;
    *y = temp;
}

//here n = Arr.size()
template<class T>
void SelectionSort(T Arr[], int n){
    int i,j,k;
    for(i = 0; i < n-1; i++){
        j = i;
        for(k = i+1; k < n; k++){
            if(Arr[k] < Arr[j]){
                j = k;
            }
        }
        swapdata(&Arr[i],&Arr[j]);
    }
}

int main(){
    int Arr[] = {32, -5, 1, 12, 300, 6, 87, 10};
    float A[] = {3.2,-1.5,4.0,-12};
    char ch[] = {'z','a','m','e','o'};
    SelectionSort(Arr,8);
    Display(Arr,8);
    SelectionSort(A,4);
    Display(A,4);
    SelectionSort(ch,5);
    Display(ch,5);
    return 0;
}