//As we know in array ADT we've data members and member functions
//NOTE: in class ADT, elements stored in array will not be of specific data type but of generic data type.
//Generic data type = using template
//Will use exception handling for indexoutofbound, badinput exception etc
//Lecture 37


//NOTE: In C++, you are not allowed to specify a default value for the same parameter in both the declaration and definition of a function or constructor.

#include<iostream>
using namespace std;
class IllegalParametervalue{
    private:
    string message;
    public:
    IllegalParametervalue(string msg){
        message = msg;
    }
    void display_exception(){
        cout<<message<<endl;
    }
};
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
    void Delete(int position,T &element); //small 'delete' specify delete(used to release memory) hence we use 'Delete'
    bool Find(int position, T &element);
    int Search(T element);
    int length();
    void Display();
    bool isEmpty();
    bool isFull();
    T Get(int index); //return data element T
    void set(int index, T); //takes data element T and sets it
    int Findmax();
    int Findmin();
    int SumofArray();
    int Average();
    void Append(T element);
    int IndexOf(T element);//index of the given data element
};
template<class T> //remember to write this for each implementation 
ArrayADT<T> :: ArrayADT(int x){ //Don't forget to write <T> while using scope resoultion with classname
    if(x < 1){
        throw IllegalParametervalue("Capacity can't be negative or zero...");
    }
    capacity = x;
    size = 0;
    Arr = new T [capacity];
    cout<<"Constructor called and array got created \n";
}

template<class T>
ArrayADT<T>:: ~ArrayADT(){
    delete [] Arr;
    cout<<"Destructor called \n";
}

template<class T>
void ArrayADT<T>::insert(int position,T element){
    if(position < 1 || position > size + 1){
        throw IllegalParametervalue("Invalid Position!");
    }
    for(int i = size-1; i>= position-1;i--){
        Arr[i+1] = Arr[i];
    }
    Arr[position-1] = element;
    size++;
}
template<class T>
void ArrayADT<T>:: Delete(int position, T &element){
    if(position < 1 || position > size){
        throw IllegalParametervalue("Invalid position to delete");
    }
    for(int i=position;i<size;i++){
        Arr[i-1] = Arr[i];
    }
    size--;
}

template<class T>
bool ArrayADT<T>:: Find(int position,T &element){
    if(position <1 || position > size){
        return false;
    }
    element = Arr[position-1];
    return true;
}

template<class T>
int ArrayADT<T>::Search(T element){
    for(int i=0;i<size;i++){
        if(Arr[i] == element){
            return i+1;
        }
    }
    return -1;
}
template<class T>
void ArrayADT<T>::Display(){
    for(int i=0;i<size;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<"\n";
}

template<class T>
int ArrayADT<T>::length(){
    return size;
}

template<class T>
bool ArrayADT<T>::isEmpty(){
    if(size == 0) return true;
    else return false;
}

template<class T>
bool ArrayADT<T>::isFull(){
    if(size == capacity) return true;
    else return false;
}

template<class T>
T ArrayADT<T>::Get(int index){
    if(index < 0 || index >= size){
        cout<<"Invalid"<<endl;
    }
    else{
        return Arr[index];
    }
}

template<class T>
void ArrayADT<T>::set(int index, T element){
    if(index < 0 || index >= size){
        cout<<"Invalid"<<endl;
    }
    else{
        Arr[index] = element;
    }
}

template<class T>
int ArrayADT<T>::Findmax(){
    int max = Arr[0];
    for(int i=1;i<size;i++){
        if(Arr[i] > max){
            max = Arr[i];
        }
    }
    return max;
}

template<class T>
int ArrayADT<T>::Findmin(){
    int min = Arr[0];
    for(int i=1;i<size;i++){
        if(Arr[i] < min){
            min = Arr[i];
        }
    }
    return min;
}

template<class T>
int ArrayADT<T>::SumofArray(){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += Arr[i];
    }
    return sum;
}

template<class T>
int ArrayADT<T>::Average(){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum += Arr[i];
    }
    return sum/size;
}

template<class T>
void ArrayADT<T>::Append(T element){
    Arr[size] = element;
    size++;
}


template<class T>
int ArrayADT<T>::IndexOf(T element){
    for(int i=0;i<size;i++){
        if(Arr[i] == element){
            return i;
        }
    }
}

int main(){
    try{
        int x;
        bool ans;
        ArrayADT<int> A(10);
        A.insert(1,18);
        A.insert(2,41);
        A.insert(3,34);
        A.insert(1,12);
        A.insert(4,23);
        A.insert(5,81);
        //A.insert(9,0); -----for checking error
        A.Display();
        A.Delete(2,x);
        //A.Delete(9,x); -----for checking error
        A.Display();
        cout<<"element at given position(Find) true(1)/False(0): "<<A.Find(2,x)<<endl;
        cout<<"Element at pos(search): "<<A.Search(81)<<endl;
        cout<<"Size of the array/length: "<<A.length()<<endl;
        cout<<"isEmpty()?: "<<A.isEmpty()<<endl;
        cout<<"isFull()?: "<<A.isFull()<<endl;
        cout<<"element at index 2 using get(): "<<A.Get(2)<<endl;
        A.set(2,1005);
        A.Display();
        cout<<"Maximum: "<<A.Findmax()<<endl;
        cout<<"Minimum: "<<A.Findmin()<<endl;
        cout<<"Sum of Array: "<<A.SumofArray()<<endl;
        cout<<"Average: "<<A.Average()<<endl;
        A.Append(23);
        A.Display();
        cout<<"Index of element 23: "<<A.IndexOf(23)<<endl;
    }
    catch(IllegalParametervalue e){
        e.display_exception();
    }
}