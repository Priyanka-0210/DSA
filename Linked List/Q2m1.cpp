//Q2m1.cpp = Q2 method 1.cpp
//Concatenation using method1 - Concatenating LL2 at the end of LL1 by pointing last node of LL1 to LL2's head
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
    private:
        Node<T> *head;
        Node<T> *tail;
        int len;
    public:
        Chain();
        ~Chain();
        void ConcatenateMethod1(Chain<T> &LL1, Chain<T> &LL2);
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


//Instead of traversing one can use 'tail' too to concatenate efficiently
//If we use traversal technique it takes O(n) time complexity
//whereas 'tail' technique takes O(1) time complexity
template<class T>
void Chain<T>::ConcatenateMethod1(Chain<T> &LL1, Chain<T> &LL2){
    if(LL1.head == nullptr){
        LL1.head = LL2.head;
        return;
    }
    Node<T> *temp;
    temp = LL1.head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    temp -> next = LL2.head;
}

int main(){
    Chain<int> LL1, LL2, concat_LL;
    LL1.Insert(1,10);
    LL1.Insert(2,20);
    LL1.Insert(3,30);
    LL1.Display();
    LL2.Insert(1,40);
    LL2.Insert(2,50);
    LL2.Display();

    //Method 1
    concat_LL.ConcatenateMethod1(LL1,LL2);
    cout<<"Method1 of concatenating two linked list: ";
    LL1.Display();
}