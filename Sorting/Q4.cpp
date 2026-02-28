//Merge Sort
#include<iostream>
using namespace std;

void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
}

void Merge(int Arr[], int s, int mid, int e){
    int B[e+1];
    int i = s, j = mid+1, k = s;
    while(i <= mid && j <= e){
        if(Arr[i] < Arr[j]){
            B[k] = Arr[i];
            k++;
            i++;
        }
        else{
            B[k] = Arr[j];
            k++;
            j++;
        }
    }
    for( ; i<=mid ; i++){
        B[k] = Arr[i];
        k++;
        i++;
    }
    for( ; j<=e ; j++){
        B[k] = Arr[j];
        k++;
        j++;
    }
    for(int p = s; p <= e; p++){
        Arr[p] = B[p];
    }
}

void MergeSort(int Arr[], int s, int e){
    if(s < e){
        int mid = (s+e)/2;
        MergeSort(Arr,s,mid);
        MergeSort(Arr,mid+1,e);
        Merge(Arr,s,mid,e);
    }
}

int main(){
    int Arr[] = {332, -15, 115, 112, 300, -16, 8, 90, 77};
    cout<<"Before Sorting..."<<endl;
    Display(Arr,9);
    cout<<endl;
    MergeSort(Arr,0,8);
    cout<<"After Sorting..."<<endl;
    Display(Arr,9);
    return 0;
}