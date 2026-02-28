//Merging two linked list using new list
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
        void merge(Node<T> *head1, Node<T> *head2);
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
void Chain<T>::merge(Node<T> *head1, Node<T> *head2){
    Node<T> *i = head1;
    Node<T> *j = head2;
    while(i != nullptr && j != nullptr){ // only runs when both conditions are true, when one of them gets false loop stops(other is still left with elements)
        if(i -> data > j -> data){
            Insert(len+1,j->data);
            j = j -> next;
        }
        else{
            Insert(len+1,i->data);
            i = i -> next;
        }
    }
    while(i != nullptr){
        Insert(len+1,i -> data);
        i = i -> next;
    }

    while(j != nullptr){
        Insert(len+1,j -> data);
        j = j -> next;
    }
    
}

int main(){
    Chain<int> LL1, LL2, merge_LL;
    LL1.Insert(1,5);
    LL1.Insert(2,10);
    LL1.Insert(3,15);
    LL1.Insert(4,20);
    LL1.Display();
    LL2.Insert(1,2);
    LL2.Insert(2,12);
    LL2.Insert(3,24);
    LL2.Display();
    cout<<"Merge Linked list: ";
    merge_LL.merge(LL1.head,LL2.head);
    merge_LL.Display();
}