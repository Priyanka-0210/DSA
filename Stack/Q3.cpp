//stack using linkedlist
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> *next;
};

template<class T>
class Stack{
    private:
        Node<T> *Top;
        int len;
    public:
        Stack();
        ~Stack();
        void Push(T element);
        void Pop(T &element);
        bool Find(int position, T &element);
        int Search(T element);
        int length();
        bool isEmpty();
        bool isFull(); //it's same as linkedlist 
        void Display();
};

template<class T>
Stack<T>::Stack(){
    Top = nullptr;
    len = 0;
    cout<<"Constructor called..."<<endl;
}

template<class T>
Stack<T>::~Stack(){
    Node<T> *temp = Top;
    while(temp != nullptr){
        Top = Top -> next;
        delete temp;
        temp = Top;
    }
    cout<<"Destructor called..."<<endl;
}

template<class T>
void Stack<T>::Push(T element){
    Node<T> *newnode = new Node<T>;
    newnode->data = element;
    newnode->next = nullptr;
    if(Top == nullptr){
        Top = newnode;
    }
    else{
        newnode->next = Top;
        Top = newnode;
    }
    len++;
}

template<class T>
void Stack<T>::Pop(T &element){
    if(Top == nullptr){
        cout<<"Stack underflow!"<<endl;
        return;
    }
    element = Top->data;
    Node<T> *temp = Top;
    Top = Top -> next;
    delete temp;
    len--;
}

template<class T>
bool Stack<T>::Find(int position, T &element){
    if(position < 1 || position > len){
        cout<<"Invalid position!"<<endl;
        return false;
    }
    Node<T> *temp = Top;
    for(int i = 1; i < position; i++){
        temp = temp -> next;
    }
    element = temp -> data;
    return true;
}

template<class T>
int Stack<T>::Search(T element){
    Node<T> *temp = Top;
    for(int i = 1; i < len; i++){
        if(temp->data == element){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

template<class T>
bool Stack<T>::isEmpty(){
    if(Top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
int Stack<T>::length(){
    return len;
}

template<class T>
void Stack<T>::Display(){
    Node<T> *temp = Top;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int x;
    Stack<int> s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Display();
    s.Pop(x);
    cout<<"Deleted element: "<<x<<endl;
    s.Display();
    s.Find(2,x);
    cout<<"Element at 2nd position: "<<x<<endl;
    cout<<"search found at: "<<s.Search(30)<<endl;
    cout<<"length: "<<s.length()<<endl;
    cout<<"isEmpty? : "<<s.isEmpty()<<endl;
}