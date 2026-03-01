//Radix Sort OR Base Sort 
#include<iostream>
using namespace std;

void CountingSort(int Arr[], int n, int place){
    const int max = 10;
    int output[n]; //can use vector too
    int count[max];
    for(int i = 0; i < max; i++){
        count[i] = 0;
    }
    for(int i = 0; i < n; i++){
        count[(Arr[i]/place) % 10]++;
    }
    for(int i = 1; i < max; i++){
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--){
        output[count[(Arr[i]/place) % 10] - 1] = Arr[i];
        count[(Arr[i]/place) % 10]--;
    }
    for(int i = 0; i < n; i++){
        Arr[i] = output[i];
    }
}

void RadixSort(int Arr[], int n){
    int maximum = Arr[0];
    for(int i = 0; i < n; i++){
        if(Arr[i] > maximum) maximum = Arr[i];
    }
    for(int place = 1; (maximum/place) > 0; place *= 10){
        CountingSort(Arr,n,place); //Any sorting technique could be choosen
    }
}

void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
}

int main(){
    int Arr[10] = {7,3,3,8,1,0,6};
    cout<<"Before sorting: ";
    Display(Arr,7);
    RadixSort(Arr,7);
    cout<<endl;
    cout<<"After sorting: ";
    Display(Arr,7);
}