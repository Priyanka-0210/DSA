//Quick Sort
#include<iostream>
using namespace std;

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

template<class T>
int Partition(T Arr[], int l, int h){
    T pivot = Arr[l];
    int i = l, j = h;
    do{
        do{
            i++;
        }while(Arr[i] <= pivot);
        do{
            j--;
        }while(Arr[j] > pivot);
        if(i < j) swapdata(&Arr[i], &Arr[j]);
    }while(i < j);
    swapdata(&Arr[j],&Arr[l]);
    return j;
}

template<class T>
void QuickSort(T Arr[], int l, int h){
    if(l < h){
        int j = Partition(Arr,l,h);
        QuickSort(Arr,l,j);
        QuickSort(Arr,j+1,h);
    }
}

int main(){
    int Arr[] = {32,-15,115,12,300,-6,8,190,77};
    cout<<"Before sorting..."<<endl;
    Display(Arr,9);
    cout<<endl;
    QuickSort(Arr,0,9); //here at index 9 there would be some garbage value which works as infinity
    cout<<"After sorting..."<<endl;
    Display(Arr,9);
    cout<<endl;
    return 0;
}

