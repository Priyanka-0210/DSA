//Binary Class ADT (using Queue)
//We're using queue for all traversals
#include<iostream>
#include "queueclass.cpp"
using namespace std;

template<class T>
class Node{
    public:
        T Data;
        Node<T> *Lchild;
        Node<T> *Rchild;
};

template<class T>
class BinaryTree{
    public:
        Node<T> *root;
        BinaryTree();
        ~BinaryTree();
        Node<T> *newnode(T Data);
        void Preorder(Node<T> *temp);
        void Inorder(Node<T> *temp);
        void Postorder(Node<T> *temp);
        void Levelorder(Node<T> *temp);
        int Height(Node<T> *temp);
        int countnodes(Node<T> *temp);
        Node<T> *getRoot();
};

template<class T>
BinaryTree<T>::BinaryTree(){
    cout<<"Constructor is called..."<<endl;
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree(){
    cout<<"Destructor is called..."<<endl;
}

template<class T>
Node<T> * BinaryTree<T>::newnode(T Data){
    Node<T> *temp = new Node<T>;
    temp->Data = Data;
    temp -> Lchild = nullptr;
    temp -> Rchild = nullptr;
    return temp;
}

template<class T>
void BinaryTree<T>::Preorder(Node<T> *temp){
    if(temp != nullptr){
        cout<<temp->Data<<" ";
        Preorder(temp -> Lchild);
        Preorder(temp -> Rchild);
    }
}

template<class T>
void BinaryTree<T>::Inorder(Node<T> *temp){
    if(temp != nullptr){
        Inorder(temp -> Lchild);
        cout<<temp->Data<<" ";
        Inorder(temp -> Rchild);
    }
}

template<class T>
void BinaryTree<T>::Postorder(Node<T> *temp){
    if(temp != nullptr){
        Postorder(temp -> Lchild);
        Postorder(temp -> Rchild);
        cout<<temp->Data<<" ";
    }
}

template<class T>
void BinaryTree<T>::Levelorder(Node<T> *temp){
    if(temp == nullptr) return;
    Queue<Node<T>*> q(10);
    q.EnQueue(temp);
    while(!q.isEmpty()){
        q.DeQueue(temp);
        cout << temp->Data << " ";
        if(temp->Lchild != nullptr){
            q.EnQueue(temp->Lchild);
        }
        if(temp->Rchild != nullptr){
            q.EnQueue(temp->Rchild);
        }
    }
}


template<class T>
int BinaryTree<T>::Height(Node<T> *temp){
    int l = 0, r = 0;
    if(temp == nullptr) return 0;
    l = Height(temp -> Lchild);
    r = Height(temp -> Rchild);
    if(l > r) return l + 1;
    else return r + 1;
}

template<class T>
int BinaryTree<T>::countnodes(Node<T> *temp){
    if(temp == nullptr) return 0;
    return countnodes(temp->Lchild) + countnodes(temp->Rchild) + 1;
}

template<class T>
Node<T> * BinaryTree<T>::getRoot(){
    return root;
}

int main(){
    BinaryTree<int> BT;
    Node<int> *P;
    P = BT.newnode(1);
    P->Lchild = BT.newnode(2);
    P->Rchild = BT.newnode(3);
    P->Lchild->Lchild = BT.newnode(4);
    P->Lchild->Rchild = BT.newnode(5);
    P->Rchild->Lchild = BT.newnode(6);
    P->Rchild->Rchild = BT.newnode(7);
    cout<<"Inorder: ";
    BT.Inorder(P);
    cout<<endl;
    cout<<"Preorder: ";
    BT.Preorder(P);
    cout<<endl;
    cout<<"Postorder: ";
    BT.Postorder(P);
    cout<<endl;
    cout<<"Levelorder: ";
    BT.Levelorder(P);
    cout<<endl;
    cout<<"Height: "<<BT.Height(P)<<endl;
    cout<<"No of nodes: "<<BT.countnodes(P)<<endl;
}