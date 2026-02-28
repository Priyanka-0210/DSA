//DEQueue using arrays
#include<iostream>
using namespace std;

template<class T>
class DEQueue{
    private:
        T *Arr;
        int Front, Rear, size, len;
    public:
        DEQueue(int size);
        ~DEQueue();
        void insertFront(T element);
        void insertRear(T element);
        void deleteFront(T &element);
        void deleteRear(T &element);
        int length();
        T Frontmost();
        T Rearmost();
        bool isEmpty();
        bool isFull();
};

template<class T>
DEQueue<T>::DEQueue(int size){
    this->size = size;
    Arr = new T[size];
    Front = -1;
    Rear = 0;
    len = 0;
}

template<class T>
DEQueue<T>::~DEQueue(){
    delete [] Arr;
}

template<class T>
void DEQueue<T>::insertFront(T element){
    if(isFull()){
        cout<<"Queue is Full! "<<endl;
        return;
    }
    if(Front == -1){
        Front = 0;
        Rear = 0;
    }
    else if(Front == 0) Front = size - 1;
    else Front--;
    Arr[Front] = element;
    len++;
}

template<class T>
void DEQueue<T>::insertRear(T element){
    if(isFull()){
        cout<<"Queue is Full! "<<endl;
        return;
    }
    if(Front == -1){
        Front = 0;
        Rear = 0;
    }
    else if(Rear == size - 1) Rear = 0; 
    else Rear++;
    Arr[Rear] = element;
    len++;
}

template<class T>
void DEQueue<T>::deleteFront(T &element){
    if(isEmpty()){
        cout<<"Queue is Empty! "<<endl;
        return;
    }
    element = Arr[Front];
    if(Front == Rear){
        Front = -1;
        Rear = -1;
    }
    else if(Front == size - 1) Front = 0;
    else Front++;
    len--;
    cout<<"Element deleted: "<<element<<endl;
}

template<class T>
void DEQueue<T>::deleteRear(T &element){
    if(isEmpty()){
        cout<<"Queue is Empty! "<<endl;
        return;
    }
    element = Arr[Rear];
    if(Front == Rear){
        Rear = -1;
        Front = -1;
    }
    else if(Rear == 0) Rear = size - 1;
    else Rear--;
    len--;
    cout<<"Element deleted: "<<element<<endl;
}

template<class T>
T DEQueue<T>:: Frontmost(){
    if(isEmpty()){
        cout<<"Queue is Empty! "<<endl;
        return -2;
    }
    return Arr[Front];
}

template<class T>
T DEQueue<T>:: Rearmost(){
    if(isEmpty()){
        cout<<"Queue is Empty! "<<endl;
        return -2;
    }
    return Arr[Rear];
}

template<class T>
int DEQueue<T>::length(){
    return len;
}

template<class T>
bool DEQueue<T>::isEmpty(){
    return Front == -1;
}

template<class T>
bool DEQueue<T>::isFull(){
    return (Front == (Rear + 1) || ((Front == 0) && (Rear == size - 1)));
}

int main(){
    DEQueue<int> DQ(8);
    int x;
    DQ.insertFront(10);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.insertRear(20);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.insertFront(30);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.insertRear(40);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.insertFront(50);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;

    DQ.deleteFront(x);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.deleteRear(x);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.deleteFront(x);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.deleteRear(x);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
    DQ.deleteFront(x);
    cout<<DQ.Frontmost()<<" "<<DQ.Rearmost()<<endl;
}