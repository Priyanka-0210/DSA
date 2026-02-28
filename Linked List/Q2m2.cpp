//Special operations on singly linkedlist ---- concatenation
//method 2 - Create a new list with all elements (deep copy)
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
        void Concatenate(Chain<T> *head1, Chain<T> *head2);
        void Insert(int position,T element);
        void Display();
};

template<class T>
Chain<T>::Chain(){
    head = NULL;
    tail = NULL;
    len = 0;
    cout<<"Constructor called..."<<endl;
}

template<class T>
Chain<T>::~Chain(){
    Node<T> *temp;
    temp = head;
    while(temp != NULL){
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
    newnode->next = NULL;
    if(head == NULL){
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
void Chain<T>::Concatenate(Chain<T> *LL1, Chain<T> *LL2) {
    Node<T> *temp;
    temp = LL1->head;
    while (temp != NULL) {
        Insert(len + 1, temp->data); // insert at the end
        temp = temp->next;
    }

    temp = LL2->head;
    while (temp != NULL) {
        Insert(len + 1, temp->data); // insert at the end
        temp = temp->next;
    }

    cout << "Concatenated list: ";
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
    concat_LL.Concatenate(&LL1 , &LL2);
    concat_LL.Display();
}