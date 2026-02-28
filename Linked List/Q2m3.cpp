//Singly Linkedlist concatenation using method2
//method 3 - Recursively Append second list (LL2)
#include<iostream>
using namespace std;
template<class T>
class Node{
    public:
        T data;
        Node<T> *next;
};

template<class T>
class Chain{        
    public:
        Node<T> *head;
        Node<T> *tail;
        int len;
        Chain();
        ~Chain();
        void Insert(int position,T element);
        void Display();
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
    Node<T> *temp;
    temp = head;
    while(temp != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
    cout<<"Destructor called..."<<endl;
}

template<class T>
void Chain<T>::Insert(int position, T element){
    Node<T> *newnode;
    newnode = new Node<T>;
    newnode->data = element;
    newnode->next = nullptr;
    if(head == nullptr){
        head = newnode;
        tail = newnode;
    }
    else{
        if(position == 1){
            newnode->next = head;
            head = newnode;
        }
        else if(position == (len + 1)){ // one can also use traversal method
            tail->next = newnode;
            tail = newnode;
        }
        else{
            Node<T> *temp;
            temp = head;
            for(int i = 1; i < position - 1; i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
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
Node<T>* ConcatenateMethod3(Node<T>* LL1, Node<T>* LL2){
    if(LL1 == nullptr){
        return LL2;
    }
    LL1->next = ConcatenateMethod3(LL1->next,LL2);
    return LL1;
}

int main(){
    Chain<int> LL1, LL2;
    LL1.Insert(1,10);
    LL1.Insert(2,20);
    LL1.Insert(3,30);
    LL1.Display();
    LL2.Insert(1,40);
    LL2.Insert(2,50);
    LL2.Display();

    //Method 1
    LL1.head = ConcatenateMethod3(LL1.head,LL2.head);
    LL2.head = nullptr; //to solve the issue (the code keeps running reasons at the end)
    cout<<"Method3 of concatenating two linked list: ";
    LL1.Display();
}


//Reason: Ater concatenation, both LL1 and LL2 point to the same list nodes. 
//When the destructor is called for both objects, the same nodes are deleted twice, causing a crash or infinite loop.
//To fix this, we set LL2.head = nullptr; so it doesn't try to delete nodes that now belong to LL1. 