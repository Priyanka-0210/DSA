//class ADT for circular singly linked list: --- Basic Operation
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> *next;
};

template<class T>
class CLL{
    public:
    Node<T> *head;
    Node<T> *tail;
    int len;
    CLL();
    ~CLL();
    void Insert(int position, T element);
    void Delete(int position, T &element);
    bool Find(int positon, T &element);
    int Search(T element);
    int length();
    void Display();
    bool isEmpty();
    bool isFull();
    //There is no such concept as isFull with respect to linkedlist, 
    //it can be applicable only when we're trying to allocate the memory and memory isn't available
};

template<class T>
CLL<T>::CLL(){
    head = nullptr;
    tail = nullptr;
    len = 0;
    cout<<"constructor called..."<<endl;
}

template<class T>
CLL<T>::~CLL(){
    while(tail != head){ //one can you traversal technique instead of tail
        tail->next = head->next;
        delete head;
        head = tail->next;
    }
    if(tail == head){
        delete head;
        head = tail = nullptr;
    }
    cout<<"destructor called..."<<endl;
}

template<class T>
void CLL<T>::Insert(int position, T element){
    Node<T> *newnode = new Node<T>;
    newnode -> data = element;
    newnode -> next = newnode;
    if(len == 0){
        head = newnode;
        tail = newnode;
    }
    else{
        if(position == 1){
            newnode->next = head;
            tail->next = newnode;
            //we can use traversal technique, instead of traversing it till nullptr
            //we use it's length to traverse just like we do for inserting at middle position
            //NOTE: circular linked list don't have nullptr
            head = newnode;
        }
        else if(position == (len + 1)){
            tail->next = newnode;
            newnode->next = head;
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
void CLL<T>::Display(){
    Node<T> *temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp != head){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<"\n";
}

template<class T>
void CLL<T>::Delete(int position, T &element){
    if(len == 0){
        cout<<"LL is empty"<<endl;
        return;
    }
    else{
        if(position == 1){
            if(head == tail){
                delete head;
                head = tail = nullptr;
            }
            else{
            Node<T> *temp;
            temp = head;
            head = head -> next;
            tail->next = head;
            element = temp->data;
            cout<<"Deleted element: "<<element<<endl;
            delete temp;
        }
        }
        else if(position == len){
            Node<T> *p = head;
            Node<T> *q;
            for(int i = 1; i < position-1; i++){
                p = p -> next;
            }
            q = p->next;
            p->next = head;
            tail = p;
            element = q->data;
            cout<<"Deleted element: "<<element<<endl;
            delete q;
        }
        else{
            Node<T> *p = head;
            Node<T> *q;
            for(int i=1;i<position-1;i++){
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            element = q->data;
            cout<<"Deleted element: "<<element<<endl;
            delete q;
        }
    }
    len--;
}

template<class T>
bool CLL<T>::Find(int position,T &element){
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
int CLL<T>::Search(T element){
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
int CLL<T>::length(){
    return len;
}

template<class T>
bool CLL<T>::isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    CLL<int> C;
    int x;
    C.Insert(1,10);
    C.Insert(2,20);
    C.Insert(3,30);
    C.Insert(4,40);
    C.Insert(5,50);
    C.Insert(1,5);
    C.Insert(4,25);
    C.Display();
    C.Delete(1,x);
    C.Display();
    C.Delete(6,x);
    C.Display();
    C.Delete(13,x);
    C.Display();
    cout<<C.Find(2,x)<<endl;
    cout<<C.Search(20)<<endl;
    cout<<"isEmpty: "<<C.isEmpty()<<endl;
    cout<<"length: "<<C.length()<<endl;
}