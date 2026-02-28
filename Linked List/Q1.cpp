//class ADT for singly linked list ----- BASIC OPERATION
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
        void Insert(int position, T element);
        void Delete(int position, T &element);
        bool Find(int position, T &element);
        int Search(T element);
        void Display();
        int Length(); //OR int count();
        bool isEmpty();
        bool isFull();
        //There is no such concept as isFull with respect to linkedlist, 
        //it can be applicable only when we're trying to allocate the memory and memory isn't available
};

//Constructor
template<class T>
Chain<T>::Chain(){
    head = NULL;
    tail = NULL;
    len = 0;
    //we will allocate the memory in the constructor but in insert function
    cout<<"Constructor called!"<<endl;
}

//Destructor
template<class T>
Chain<T>::~Chain(){
    Node<T> *temp;
    temp = head;
    while(temp != NULL){
        head = head -> next;
        delete temp;
        temp = head;
    }
    cout<<"Destructor called!"<<endl;
}

//Inserting in Linked List
template<class T>
void Chain<T>::Insert(int position, T element){
    Node<T> *newnode;
    newnode = new Node<T>;
    newnode->data = element;
    newnode->next = NULL;
    if(head == NULL){ // one can also check like if(len == 0){  }
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
void Chain<T>::Delete(int position, T &element){
    if(head == NULL){
        cout<<"List is empty";
        return;
    }
    Node<T> *temp1;
    Node<T> *temp2;
    temp1 = head;
    if(position == 1){
        head = head -> next;
        element = temp1 -> data;
        delete temp1;
    }
    else if(position == len){
        for(int i = 1; i < position - 1; i++){
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;
        element = temp2 -> data;
        delete temp2;
        tail = temp1;
        temp1 -> next = NULL;
    }
    else{
        for(int i=1;i < position - 1;i++){
            temp1 = temp1 -> next;
        }
        temp2 = temp1 -> next;
        element = temp2 -> data;
        temp1 -> next = temp2 -> next;
        delete temp2;
    }
    cout<<"element deleted: "<<element<<endl;
    len--;
}

template<class T>
bool Chain<T>::Find(int position,T &element){
    if(position < 1 || position > len){
        return false;
    }
    Node<T> *temp;
    temp = head;
    for(int i = 1; i < position; i++){
        temp = temp -> next;
    }
    element = temp -> data;
    cout<<"element using find() operation: "<<element<<endl;
    return true;
}

template<class T>
int Chain<T>::Search(T element){
    Node<T> *temp;
    temp = head;
    for(int i=1; i <= len; i++){
        if(element == temp -> data){
            return i;
        }
        temp = temp -> next;
    }
    return -1;
}

template<class T>
bool Chain<T>::isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
int Chain<T>::Length(){
    return len;
}

template<class T>
void Chain<T>::Display(){
    Node<T> *temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

int main(){
    Chain<int> C;
    int w,x,y,z;
    C.Insert(1,10);
    C.Insert(2,20);
    C.Insert(3,30);
    C.Insert(4,40);
    C.Insert(5,50);
    C.Insert(4,35);
    C.Insert(1,5);
    C.Display();
    C.Delete(1,x);
    C.Display();
    C.Delete(6,y);
    C.Display();
    C.Delete(3,z);
    C.Display();
    cout<<C.Find(2,w)<<endl;
    cout<<C.Search(35)<<endl;
    cout<<"IsEmpty(): "<<C.isEmpty()<<endl;
    cout<<"Length: "<<C.Length()<<endl;
}