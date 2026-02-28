//Detect cycle in a linkedlist - floyd's cycle detection algorithm OR Tortoise and Hare algorithm
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
        void Insert(int position, T element);
        void Display();
        bool check();
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
void Chain<T>::Display(){
    Node<T> *temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}

template<class T>
bool Chain<T>::check(){
    Node<T> *slow = head;
    Node<T> *fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
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
    C.head->next->next->next->next = C.head->next->next;
    cout<<"Cycle detected?  "<<C.check()<<endl;
}