//Heapify process

//TIME COMPLEXITY: O(n/2) - half the time of normal heap 
#include<iostream>
using namespace std;

//Max Heap using Heapify process
template<class T>
class MaxHeap{
    private:
        T *Arr;
        int n; //No of data elements in an array (inshort - size of an array)
    public:
        MaxHeap(int size);
        void Display();
        void Heapify(int n);
        void DelMax(int n, T &x);
        void Adjust(int i, int n);
        void HeapSort();

};

template<class T>
MaxHeap<T>::MaxHeap(int size){
    if(size < 0) throw "size must be greater than zero!";
    n = size;
    Arr = new T[n+1]; //0 to n values accessible
    for(int i = 1; i <= n; i++){
        cout<<"Enter element "<<i<<" : ";
        cin>>Arr[i];
    } 
    //We ignore Arr[0] and focus on Arr[1] as heap uses 1 based indexing
    //Arr[0] contains garbage values.
}

template<class T>
void MaxHeap<T>::Display(){
    for(int i = 1; i <= n; i++){
        cout<<Arr[i]<<" ";
    }
}


template<class T>
void MaxHeap<T>::Heapify(int n){
    for(int i = n/2; i >= 1; i--){
        Adjust(i,n);
    }
}

template<class T>
void MaxHeap<T>::Adjust(int i, int n){
    int j = 2 * i;
    T root = Arr[i]; //The last value of an array which came replace the max value.
    while(j <= n){
        if(j < n && (Arr[j] < Arr[j+1])){
            j = j + 1; //2 * i + 1
        }
        if(root >= Arr[j]){
            break;
        }
        Arr[j/2] = Arr[j]; //substituting value of root at Arr[j];
        j = 2 * j; //Incrementing value of j
    }
    //When we reach at the end(condition became false) we substitude Arr[j/2] (maximum value in whole tree) into the root.
    Arr[j/2] = root; 
}

template<class T>
void MaxHeap<T>::DelMax(int n,T &x){
    if(n == 0){
        cout<<"Heap is empty! "<<endl;
    }
    else{
        x = Arr[1];
        Arr[1] = Arr[n];
        Adjust(1,n-1);
    }
}

template<class T>
void MaxHeap<T>::HeapSort(){
    T x;
    //Phase 1 - Inserting element
    Heapify(n);

    //Phase 2 - Deleting Maximum value
    for(int i = n; i >= 1; i--){
        DelMax(i,x);
        Arr[i] = x;
    }
}

int main(){
    try{
        MaxHeap<int> m(10);
        cout<<"Before sorting: ";
        m.Display();
        cout<<endl;
        m.HeapSort();
        cout<<"After Sorting (Ascending): ";
        m.Display();
    }
    catch(char *c){
        cout<<c<<endl;
    }
    return 0;
}