//Class ADT for doubly linked list --basic operation
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template<class T>
class DLL{
    private:
    Node<T> *head;
    Node<T> *tail;
    int len;
    public:
    DLL();
    ~DLL();
    void Insert(int position, T element);
    void Delete(int position, T &element);
    bool Find(int position, T &element);
    int Search(T element);
    bool isEmpty();
    bool isFull();
    int length();
    void Display();
};

template<class T>
DLL<T>::DLL(){
    head = tail = nullptr;
    len = 0;
    cout<<"Constructor called..."<<endl;
}

template<class T>
void DLL<T>::Insert(int position, T element){
    Node<T> *newnode = new Node<T>;
    newnode->data = element;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    if(head == nullptr){
        head = tail = newnode;
    }
    else{
        if(position == 1){
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        else if(position == (len+1)){
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        else{
            Node<T> *temp = head;
            for(int i = 1; i < position - 1; i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            temp->next->prev = newnode;
        }
    }
    len++;
}

template<class T>
void DLL<T>::Delete(int position, T &element){
    if(head == nullptr){
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    else{
        if(position == 1){
            Node<T> *temp = head;
            head = head->next;
            element = temp->data;
            cout<<"Deleted element: "<<element<<endl;
            delete temp;
            head->prev = nullptr;
        }
        else if(position == len){
            Node<T> *temp = tail;
            tail = tail->prev;
            element = temp->data;
            cout<<"Deleted element: "<<element<<endl;
            delete temp;
            tail->next = nullptr;
        }
        else{
            Node<T> *p = head;
            Node<T> *q = nullptr;
            for(int i = 1; i < position - 1; i++){
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            q->next->prev = p;
            element = q->data;
            cout<<"Deleted element: "<<element<<endl;
            delete q;
        }
    }
    len--;
}

template<class T>
bool DLL<T>::Find(int position,T &element){
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
int DLL<T>::Search(T element){
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
bool DLL<T>::isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
void DLL<T>::Display(){
    Node<T> *temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

template<class T>
int DLL<T>::length(){
    return len;
}

template<class T>
DLL<T>::~DLL(){
    Node<T> *temp = head;
    while(temp != nullptr){
        head = head -> next;
        delete temp;
        head->prev = nullptr;
        temp = head;
    }
    cout<<"Destructor called..."<<endl;
}

int main(){
    DLL<int> D;
    int x;
    D.Insert(1,5);
    D.Insert(2,10);
    D.Insert(3,15);
    D.Insert(4,20);
    D.Insert(5,25);
    D.Insert(1,1);
    D.Insert(5,56);
    D.Display();
    cout<<"\n";
    cout<<"length: "<<D.length()<<endl;
    D.Delete(1,x);
    D.Display();
    D.Delete(6,x);
    D.Display();
    D.Delete(3,x);
    D.Display();
    cout<<"\n";
    cout<<"length: "<<D.length()<<endl;
    cout<<D.Find(2,x)<<endl;
    cout<<D.Search(20)<<endl;
    cout<<"isEmpty: "<<D.isEmpty()<<endl;
}