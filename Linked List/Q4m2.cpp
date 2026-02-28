//reversing a linked list using pointers
#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
    T data;
    Node<T>* next;
};

template<class T>
class Chain{
    public:
    Node<T>* head;
    Node<T>* tail;
    int len;
    Chain();
    ~Chain();
    void Insert(int position,T element);
    void Display();
    void reverse();
};

template<class T>
Chain<T>::Chain(){
    head = nullptr;
    tail = nullptr;
    len = 0;
    cout<<"Constructor called..."<<endl;
}

template<class T>
Chain<T>::~Chain(){
    Node<T> *temp; //pointer which points to node type
    temp = head;
    while(temp != nullptr){
        head = head -> next;
        delete temp;
        temp = head;
    }
    cout<<"Destructor called..."<<endl<<flush;
}

template<class T>
void Chain<T>::Insert(int position, T element){
    Node<T> *newnode; //newnode is a pointer which points to node type
    newnode = new Node<T>; //created new node and newnode points to this new node
    newnode -> data = element;
    newnode -> next = nullptr;
    if(head == nullptr){
        head = newnode;
        tail = newnode;
    }
    else{
        if(position == 1){
            newnode -> next = head;
            head = newnode;
        }
        else if(position == (len+1)){
            tail -> next = newnode;
            tail = newnode;
        }
        else{
            Node<T> *temp;
            temp = head;
            for(int i = 1; i < position - 1; i++){
                temp = temp -> next;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
    }
    len++;
}

template<class T>
void Chain<T>::Display(){
    Node<T> *temp;
    temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

template<class T>
void Chain<T>::reverse(){
    Node<T>*nex = head;
    Node<T>*prev = nullptr;
    Node<T>* temp = head;
    while(nex != nullptr){
        nex = nex -> next;
        temp -> next = prev;
        prev = temp;
        temp = nex;
    }
    head = prev;
}

int main(){
    Chain<int> LL1;
    LL1.Insert(1,10);
    LL1.Insert(2,20);
    LL1.Insert(3,30);
    LL1.Insert(4,40);
    LL1.Insert(5,50);
    LL1.Display();
    LL1.reverse();
    LL1.Display();
}