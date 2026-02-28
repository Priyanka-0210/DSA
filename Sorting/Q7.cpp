//Counting Sort
#include<vector>
#include<iostream>
using namespace std;

void CountSort(int Arr[], int n){
    int maximum = 0;
    for(int i = 0; i < n; i++){
        if(Arr[i] > maximum) maximum = Arr[i];
    }
    int a = maximum + 1;
    vector<int> Count(a,0);
    for(int i = 0; i < n; i++){
        Count[Arr[i]]++;
    }
    int i = 0, j = 0;
    while(i <= maximum){
        if(Count[i] > 0){
            Arr[j] = i;
            j++;
            Count[i]--;
        }
        else{
            i++;
        }
    }
}

void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
}

int main(){
    int Arr[] = {2,5,7,3,3,8,1,0,6};
    cout<<"Before sorting: ";
    Display(Arr,9);
    CountSort(Arr,9);
    cout<<endl;
    cout<<"After sorting: ";
    Display(Arr,9);
}