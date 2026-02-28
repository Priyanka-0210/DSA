//Merging two linkedlist using rearranging the pointer(using dummy node)
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
    Node<T>* merge(Node<T> *head1, Node<T> *head2);
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
    cout<<"Destructor called..."<<endl;
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
Node<T>* Chain<T>::merge(Node<T> *head1, Node<T> *head2){
    Node<T>* dummy = new Node<T>;
    dummy->data = T();
    dummy->next = nullptr;
    Node<T>* curr;
    curr = dummy;
    while(head1 != nullptr && head2 != nullptr){
        if(head1 -> data <= head2 -> data){
            curr-> next = head1;
            head1 = head1 -> next;
        }
        else{
            curr -> next = head2;
            head2 = head2 -> next;
        }
        curr = curr -> next;
    }

    //for remaining elements in the linked list
    if (head1 != nullptr) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }
    return dummy->next;
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
    merge_LL.head = merge_LL.merge(LL1.head,LL2.head);
    merge_LL.Display();
    LL1.head = nullptr;
    LL2.head = nullptr;
}