//Queues using Array
#include<iostream>
using namespace std;

template<class T>
class Queue{
    private:
        T *Arr;
        int Front, Rear, size, len;
    public:
        Queue(int size);
        ~Queue();
        void EnQueue(T element);
        void DeQueue(T &element);
        bool Find(int position,T &element);
        int Search(T element);
        bool isEmpty();
        bool isFull();
        int length();
        void Display();
};

template<class T>
Queue<T>::Queue(int size){
    this->size = size;
    Arr = new T[size];
    Front = -1;
    Rear = -1;
    len = 0;
}

template<class T>
Queue<T>::~Queue(){
    delete [] Arr;
}

template<class T>
void Queue<T>::EnQueue(T element){
    if(Rear == size-1){
        cout<<"Queue is full"<<endl;
        return;
    }
    Rear++;
    Arr[Rear] = element;
    len++;
}

template<class T>
void Queue<T>::DeQueue(T &element){
    if(Front == Rear){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Front++;
    element = Arr[Front];
    len--;
}

template<class T>
bool Queue<T>::Find(int position,T &element){
    // position is 1-based relative to front
    if(position < 1 || position > len){
        cout<<"Invalid position"<<endl;
        return false;
    }
    element = Arr[Front + position];
    return true;
}

template<class T>
int Queue<T>::Search(T element){
    for(int i = Front + 1; i <= Rear; i++){
        if(element == Arr[i]){
            return i - Front; // returning 1-based position relative to queue front
        }
    }
    return -1;
}

template<class T>
bool Queue<T>::isEmpty(){
    return(Rear == Front);
}

template<class T>
bool Queue<T>::isFull(){
    return(Rear == size - 1);
}

template<class T>
int Queue<T>::length(){
    return len;
}

template<class T>
void Queue<T>::Display(){
    for(int i = Front + 1; i <= Rear; i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int x;
    Queue<int> Q(5);
    Q.EnQueue(1);
    Q.EnQueue(2);
    Q.EnQueue(3);
    Q.Display();
    Q.DeQueue(x);
    Q.Display();
    cout<<"Index found: "<<Q.Find(2,x)<<" ";
    cout<<"valid position x: "<<x<<endl;
    cout<<"len: "<<Q.length()<<endl;
    Q.EnQueue(4);
    Q.EnQueue(5);
    cout<<"Found at pos with respect to front: "<<Q.Search(2)<<endl;
    cout<<"isEmpty: "<<Q.isEmpty()<<endl;
    cout<<"isFull: "<<Q.isFull()<<endl;
    cout<<"len: "<<Q.length()<<endl;
}