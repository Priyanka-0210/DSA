//Binary search
#include<iostream>
using namespace std;
template<class T>
class BinarySearch{
    private:
    T *Arr;
    int size;
    public:
    BinarySearch(int size);
    int bsearch_using_iterative(int low,int high,T key);
    int bsearch_using_recursion(int low,int high,T key);
    int bsearch_using_divide_and_conquer(int low,int high,T key);
};

template<class T>
BinarySearch<T>::BinarySearch(int size){
    Arr = new T[size];
    cout<<"Enter "<<size<<" elements in ascending order: ";
    for(int i=0;i<size;i++){
        cin>>Arr[i];
    }
}

template<class T>
int BinarySearch<T>::bsearch_using_iterative(int low, int high, T key){
    while(low <= high){
        int mid = (low + high)/2;
        if(Arr[mid] == key){
            return mid; //Successful Search
        }
        else if(key < Arr[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1; 
        }
    }
    return -1; //Unsucessful search
}

template<class T>
int BinarySearch<T>::bsearch_using_recursion(int low, int high, T key){
    while(low <= high){
        int mid = (low + high)/2;
        if(Arr[mid] == key){
            return mid; //Successful Search
        }
        else if(key < Arr[mid]){
            return bsearch_using_recursion(low,mid-1,key);
        }
        else{
            return bsearch_using_recursion(mid+1,high,key); 
        }
    }
    return -1; //Unsucessful search
}

template<class T>
int BinarySearch<T>::bsearch_using_divide_and_conquer(int low, int high, T key){
    //Small problem
    if(low == high){
        if(Arr[low] == key){
            return low;
        }
        else{
            return -1;
        }
    }
    else{
        int mid = (low + high)/2;
        if(Arr[mid] == key){
            return mid; //Successful Search
        }
        else if(key < Arr[mid]){
            return bsearch_using_divide_and_conquer(low,mid-1,key);
        }
        else{
            return bsearch_using_divide_and_conquer(mid+1,high,key); 
        }
    }
    return -1; //Unsucessful search
}

int main(){
    int index1, index2, index3;
    BinarySearch<int> B(10);
    //iterative method
    index1 = B.bsearch_using_iterative(0,9,23);
    if(index1 == -1){
        cout<<"No Key found!"<<endl;
    }
    else{
        cout<<"Key found at index "<<index1<<endl;
    }
    //using recursion
    index2 = B.bsearch_using_recursion(0,9,81);
    if(index2 == -1){
        cout<<"No Key found!"<<endl;
    }
    else{
        cout<<"Key found at index "<<index2<<endl;
    }
    //Divide and conquer
    index3 = B.bsearch_using_divide_and_conquer(0,9,56);
    if(index3 == -1){
        cout<<"No Key found!"<<endl;
    }
    else{
        cout<<"Key found at index "<<index3<<endl;
    }
}