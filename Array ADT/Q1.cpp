//Implementation - lecture 36
#include<iostream>
using namespace std;
class Array{
    private:
        int *array;
        int capacity;
        int size;
    public:
        Array(int x = 10);
        ~Array();
        bool isFull();
        bool isEmpty();
        int SizeofArray();
        friend istream &operator >> (istream& is,Array &a);
        friend ostream &operator << (ostream& os,Array &a);
};
//It's upto us whether we wanna implement the member functions or not.

Array :: Array(int x){
    cout<<"Constructor called"<<"\n";
    capacity = x;
    array = new int[capacity]; // 'new' return an address which is stored in 'array' variable
    size = 0;
    cout<<"Array created dynamically of "<<capacity<<" capacity \n";
}

Array :: ~Array(){
    delete [] array;
}

bool Array :: isFull(){
    if(size == capacity - 1){
        return true;
    }
    return false;
}

bool Array :: isEmpty(){
    if(size == 0){
        return true;
    }
    return false;
}

int Array :: SizeofArray(){
    return size;
}

//while working with implementation of 'friend' function we don't need scope resolution operator(::) like int Array:: 
istream& operator >> (istream& is, Array &a){
    cout<<"Enter elements of an Array: ";
    is>>a.array[a.size++];
    return is;
}

ostream& operator << (ostream& os, Array &a){
    for(int i=0;i<a.size;i++){
        os<<a.array[i]<<" ";
    }
    return os;
}

int main(){
    Array a;
    int n;
    cout<<"Enter no of elements in an array: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
    }
    cout<<"Entered elements are: ";
    cout<<a;
    if(a.isFull()){
        cout<<"Array is full \n";
    }
    else{
        cout<<"Array is not full \n";
    }
    if(a.isEmpty()){
        cout<<"Array is Empty \n";
    }
    else{
        cout<<"Array is not Empty \n";
    }
    cout<<"Size of array is: "<<a.SizeofArray()<<"\n";
}