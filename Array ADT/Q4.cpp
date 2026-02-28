//Reversing an Array using ADT
#include<iostream>
using namespace std;
template<class T>
class ArrayADT{
    private:
    T *Arr;
    int size;
    int capacity;
    public:
    ArrayADT(int x);
    ~ArrayADT();
    void insert(int position,T element);
    void Display();
    void reverse_way1();
    void reverse_way2();
};

template<class T>
ArrayADT<T>:: ArrayADT(int x){
    cout<<"Constructor called \n";
    capacity = x;
    size = 0;
    Arr = new T[capacity];
}

template<class T>
ArrayADT<T>::~ArrayADT(){
    delete [] Arr;
    cout<<"Destructor called \n";
}

template<class T>
void ArrayADT<T>::insert(int position,T element){
    if(position < 1 || position > size + 1){
        cout<<"Invalid"<<endl;
        return;
    }
    for(int i = size-1; i>= position-1;i--){
        Arr[i+1] = Arr[i];
    }
    Arr[position-1] = element;
    size++;
}

template<class T>
void ArrayADT<T>::Display(){
    for(int i=0;i<size;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<"\n";
}

template<class T>
void ArrayADT<T>::reverse_way1(){
    T *temp;
    temp = new T[capacity];
    for(int i=size-1,j=0;i>=0;i--,j++){
        temp[j] = Arr[i];
    }
    for(int i=0;i<size;i++){
        Arr[i] = temp[i];
    }
}

template<class T>
void ArrayADT<T>::reverse_way2(){
    for(int i=0,j=size-1;i<=j;i++,j--){
        int temp = Arr[i];
        Arr[i] = Arr[j];
        Arr[j] = temp;
    }
}

int main(){
    ArrayADT<int> A(10);
    A.insert(1,10);
    A.insert(2,20);
    A.insert(3,30);
    A.insert(4,40);
    A.insert(5,50);
    A.insert(6,60);
    A.insert(7,70);
    A.insert(8,80);
    A.Display();
    cout<<"Reverse using Auxilary Array - temporary array:  ";
    A.reverse_way1();
    A.Display();
    cout<<"Reverse using swapping:  ";
    A.reverse_way2();
    A.Display();
}