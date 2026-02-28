//reversing a linked list using array
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
    T *arr = new T[len];
    Node<T> *temp;
    temp = head;
    int i = 0;
    while(temp != nullptr){
        arr[i] = temp -> data;
        temp = temp -> next;
        i++;
    }
    Node<T> *p = head;
    int j = len-1;
    while(p != nullptr){
        p -> data = arr[j];
        p = p -> next;
        j--;
    }
    delete [] arr;
}

int main(){
    Chain<int> LL1;
    LL1.Insert(1,5);
    LL1.Insert(2,10);
    LL1.Insert(3,15);
    LL1.Insert(4,20);
    cout<<"Linked-list: "<<endl;
    LL1.Display();
    LL1.reverse();
    cout<<"Reversed Linked-list: "<<endl;
    LL1.Display();
}