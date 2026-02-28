//Evaluate a binary expression tree
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
        int expressiontree(Node<T> *temp);
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
int BinaryTree<T>::expressiontree(Node<T> *temp){
    if(temp == nullptr) return 0;
    int l = 0, r = 0;
    l = expressiontree(temp->Lchild);
    r = expressiontree(temp->Rchild);
    if(l == 0 && r == 0) return stoi(temp->data);
    if(temp->data == "*"){
        return l * r;
    }
    else if(temp->data == "/"){
        return l / r;
    }
    else if(temp->data == "+"){
        return l + r;
    }
    else if(temp->data == "-"){
        return l - r;
    }
}

/*
                    +
                  /    \
                *        /
              /   \    /   \
            1      5  21     7
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
    BinaryTree<string> BT;
    Node<string> *P;
    P = BT.newNode("+"); //P points to the newnode we created (1) -- root node
    P->Lchild = BT.newNode("*");
    P->Rchild = BT.newNode("/");
    P->Lchild->Lchild = BT.newNode("1");
    P->Lchild->Rchild = BT.newNode("5");
    P->Rchild->Lchild = BT.newNode("21");
    P->Rchild->Rchild = BT.newNode("7");
    // P->Lchild->Lchild->Lchild = BT.newNode("10");
    // P->Lchild->Lchild->Rchild = BT.newNode("5");
    cout<<BT.expressiontree(P)<<endl;
}