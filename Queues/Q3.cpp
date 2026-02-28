//Queue using Linkedlist
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T Data;
        Node<T> *next;
};

template<class T>
class LinkedQueue{
    private:
        Node<T> *Front;
        Node<T> *Rear;
        int len = 0;
    public:
        LinkedQueue();
        ~LinkedQueue();
        void EnQueue(T element);
        void DeQueue(T &element);
        bool Find(int position,T &element);
        int Search(T element);
        bool isEmpty();
        T FrontMost();
        T RearMost();
        int length();
        void Display();
};

template<class T>
LinkedQueue<T>::LinkedQueue(){
    Front = Rear = nullptr;
    len = 0;
}

template<class T>
LinkedQueue<T>::~LinkedQueue(){
    Node<T> *temp = Front;
    while(temp != nullptr){
        Front = Front -> next;
        delete temp;
        temp = Front;
    }
    cout<<"Destructor called..."<<endl;
}

template<class T>
void LinkedQueue<T>::EnQueue(T element){
    Node<T> *newnode = new Node<T>;
    newnode -> Data = element;
    newnode -> next = nullptr;
    if(Front == nullptr){
        Front = Rear = newnode;
    }
    else{
        Rear -> next = newnode;
        Rear = newnode;
    }
    len++;
}

template<class T>
void LinkedQueue<T>::DeQueue(T &element){
    if(Front == nullptr){
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    Node<T> *temp;
    temp = Front;
    element = Front -> Data;
    Front = Front -> next;
    delete temp;
    len--;
}

template<class T>
bool LinkedQueue<T>::Find(int position,T &element){
    if(position < 1 || position > len){
        cout<<"Invalid Position"<<endl;
        return false;
    }
    int iterator = 1;
    Node<T> *temp = Front;
    while(iterator < position){
        temp = temp->next;
        iterator++;
    }
    element = temp->Data;
    cout<<"Element(Find): "<<element<<endl;
    return true;
}

template<class T>
int LinkedQueue<T>::Search(T element){
    Node<T> *temp = Front;
    for(int i = 1; temp != nullptr; i++){
        if(temp -> Data == element){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

template<class T>
T LinkedQueue<T>::FrontMost(){
    return Front->Data;
}

template<class T>
T LinkedQueue<T>::RearMost(){
    return Rear -> Data;
}

template<class T>
int LinkedQueue<T>::length(){
    return len;
}

template<class T>
bool LinkedQueue<T>::isEmpty(){
    return Rear == nullptr;
}

template<class T>
void LinkedQueue<T>::Display(){
    Node<T> *temp = Front;
    while(temp != nullptr){
        cout<<temp->Data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    int x;
    LinkedQueue<int> LQ;
    cout<<LQ.isEmpty()<<endl;
    LQ.Display();
    LQ.EnQueue(10);
    cout<<LQ.FrontMost()<<" "<<LQ.RearMost()<<endl;
    LQ.EnQueue(20);
    cout<<LQ.FrontMost()<<" "<<LQ.RearMost()<<endl;
    LQ.EnQueue(30);
    cout<<LQ.FrontMost()<<" "<<LQ.RearMost()<<endl;
    LQ.DeQueue(x);
    cout<<LQ.FrontMost()<<" "<<LQ.RearMost()<<endl;
    LQ.EnQueue(50);
    cout<<LQ.FrontMost()<<" "<<LQ.RearMost()<<endl;
    LQ.EnQueue(60);
    cout<<LQ.FrontMost()<<" "<<LQ.RearMost()<<endl;
    LQ.Display();
    cout<<LQ.length()<<endl;
    cout<<LQ.isEmpty()<<endl;
    cout<<LQ.Find(3,x)<<endl;
    cout<<"Index of element: "<<LQ.Search(60)<<endl;
}