//Merging two linked list using recursion
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
Node<T>* Chain<T>::merge(Node<T> *head1, Node<T> *head2){
    if(head1 == nullptr || head2 == nullptr){
        return head1 == nullptr ? head2 : head1; //Ternary Operator
    }
    if(head1 -> data <= head2 -> data){
        head1 -> next = merge(head1 -> next, head2);
        return head1;
    }
    else{
        head2 -> next = merge(head1, head2 -> next);
        return head2;
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
    merge_LL.head = merge_LL.merge(LL1.head,LL2.head); //merge_LL.head will point to the same node (same address in memory) that the merge() function returned.
    //To solve infinte loops problem because LL1 and LL2 no longer contain their original LL thus we make them point to nothing(nullptr)
    LL1.head = nullptr;
    LL2.head = nullptr;
    merge_LL.Display();
}

//"If LL1.head and head1 point to the same node, and I change head1->next, then the node that LL1.head points to is modified, so the linked list LL1 changes too."

/*

TO UNDERSTAND BELOW LINES CHECK DRY RUN IN DSA BOOK

After merge, LL1.head and LL2.head still point to the same original first nodes (5 and 2), but:
The next pointers inside those nodes may now point to new merged nodes.
So the internal structure of LL1 and LL2 is changed, even if the head pointer remains the same.
*/