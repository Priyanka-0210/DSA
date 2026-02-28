//Check children sum property
#include<iostream>
#include "stackclass.cpp"
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node<T> *Lchild;
    Node<T> *Rchild;
};

template<class T>
class BinaryTree{
    public:
        Node<T> *root;
        BinaryTree();
        ~BinaryTree();
        Node<T> *newNode(T data); //Inserting in a binary tree
        int childrensum(Node<T> *temp);
};

template<class T>
BinaryTree<T>::BinaryTree(){
    cout<<"Constructor is called! "<<endl;
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree(){
    cout<<"Destructor is called! "<<endl;
}

template<class T>
int BinaryTree<T>::childrensum(Node<T> *temp){
    if(temp == nullptr) return 0;
    if(temp->Lchild == nullptr && temp->Rchild == nullptr) return temp->data;
    int l = childrensum(temp->Lchild);
    int r = childrensum(temp->Rchild);
    if(temp->data == (l+r) && l != -1 && r != -1){
        return temp->data;
    }
    return -1;
}

/*
                    9
                  /    \
                4        5
              /   \    /   \
            1      3  3     2
*/

template<class T>
Node<T> * BinaryTree<T>::newNode(T data){
    root = new Node<T>;
    root->data = data;
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    return root; //Because of this we need to keep Node<T> *root in public and not in private
}



int main(){
    BinaryTree<int> BT;
    Node<int> *P;
    P = BT.newNode(9); //P points to the newnode we created (1) -- root node
    P->Lchild = BT.newNode(4);
    P->Rchild = BT.newNode(5);
    P->Lchild->Lchild = BT.newNode(1);
    P->Lchild->Rchild = BT.newNode(3);
    P->Rchild->Lchild = BT.newNode(3);
    P->Rchild->Rchild = BT.newNode(2);
    if(BT.childrensum(P) == -1){
        cout<<"Doesn't follow children sum's property"<<endl;
    }
    else{
        cout<<"Follows children sum's property"<<endl;
    }
}