//Circular Queue using arrays
#include<iostream>
using namespace std;

template<class T>
class CQueue{
    private:
        T *Arr;
        int Front, Rear,size,len;
    public:
        CQueue(int size);
        ~CQueue();
        void EnQueue(T element);
        void DeQueue(T &element);
        T FrontElement();
        T RearElement();
        bool isEmpty();
        bool isFull();
        int length();
        void Display();
};

template<class T>
CQueue<T>::CQueue(int size){
    this->size = size;
    Arr = new T[size];
    Front = 0;
    Rear = 0;
    len = 0;
}

template<class T>
CQueue<T>::~CQueue(){
    delete [] Arr;
}

template<class T>
void CQueue<T>::EnQueue(T element){
    if(Front == (Rear + 1 % size)){
        cout<<"Queue is Full"<<endl;
        return;
    }
    Rear = (Rear + 1) % size;
    Arr[Rear] = element;
    len++; 
}

template<class T>
void CQueue<T>::DeQueue(T &element){
    if(Front == Rear){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Front = (Front + 1) % size;
    element = Arr[Front];
    len--;
}

template<class T>
T CQueue<T>::FrontElement(){
    return Arr[(Front+1) % size];
}

template<class T>
T CQueue<T>::RearElement(){
    return Arr[Rear];
}

template<class T>
int CQueue<T>::length(){
    return len;
}

template<class T>
bool CQueue<T>::isEmpty(){
    if(Front == Rear) return true;
    return false;
}

template<class T>
bool CQueue<T>::isFull(){
    if(Front == ((Rear + 1) % size)) return true;
    return false;
}

template<class T>
void CQueue<T>::Display(){
    int i;
    for(i = (Front + 1) % size; i != Rear; i = (i+1) % size){
        cout<<Arr[i]<<" ";
    }
    cout<<Arr[i]<<endl;
}

int main(){
    int x;
    CQueue<int> CQ(6);
    cout<<CQ.isEmpty()<<endl;
    CQ.EnQueue(10);
    CQ.EnQueue(20);
    CQ.EnQueue(30);
    CQ.Display();
    cout<<"     "<<CQ.FrontElement()<<" ";
    cout<<CQ.RearElement()<<endl;
    CQ.DeQueue(x);
    CQ.DeQueue(x);
    cout<<CQ.isEmpty()<<endl;
    CQ.Display();
    cout<<"     "<<CQ.FrontElement()<<" ";
    cout<<CQ.RearElement()<<endl;
    CQ.EnQueue(40);
    CQ.EnQueue(50);
    CQ.Display();
    cout<<"     "<<CQ.FrontElement()<<" ";
    cout<<CQ.RearElement()<<endl;
    CQ.EnQueue(60);
    CQ.EnQueue(70);
    CQ.Display();
    cout<<CQ.isFull()<<endl;
    cout<<CQ.isEmpty()<<endl;
    cout<<CQ.length()<<endl;
    cout<<"     "<<CQ.FrontElement()<<" ";
    cout<<CQ.RearElement()<<endl;
    cout<<"Trying full Queue thing: "<<endl;
    CQ.EnQueue(80);
}