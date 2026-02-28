//Binary Class ADT (using stack)
//As we're using stack here levelorder traversal won't be there as it uses queue data structure

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
        void TraversePreOrder(Node<T> *temp); //Recursive
        void TraverseInOrder(Node<T> *temp); //Recursive
        void TraversePostOrder(Node<T> *temp); //Recursive
        void IterativePreOrder(Node<T> *temp);
        void IterativeInOrder(Node<T> *temp);
        int Height(Node<T> *temp);
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
Node<T> * BinaryTree<T>::newNode(T data){
    root = new Node<T>;
    root->data = data;
    root->Lchild = nullptr;
    root->Rchild = nullptr;
    return root; //Because of this we need to keep Node<T> *root in public and not in private
}

template<class T>
void BinaryTree<T>::TraverseInOrder(Node<T> *temp){
    if(temp != nullptr){
        TraverseInOrder(temp -> Lchild);
        cout<<temp->data<<" ";
        TraverseInOrder(temp -> Rchild);
    }
}

template<class T>
void BinaryTree<T>::TraversePreOrder(Node<T> *temp){
    if(temp != nullptr){
        cout<<temp->data<<" ";
        TraversePreOrder(temp -> Lchild);
        TraversePreOrder(temp -> Rchild);
    }
}

template<class T>
void BinaryTree<T>::TraversePostOrder(Node<T> *temp){
    if(temp != nullptr){
        TraversePostOrder(temp -> Lchild);
        TraversePostOrder(temp -> Rchild);
        cout<<temp->data<<" ";
    }
}

template<class T>
void BinaryTree<T>::IterativeInOrder(Node<T> *temp){
    Stack<Node<T> *> S(10);
    while(temp != nullptr || !S.isEmpty()){
        if(temp != nullptr){
            S.Push(temp);
            temp = temp -> Lchild;
        }
        else{
            S.Pop(temp);
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }
}

template<class T>
void BinaryTree<T>::IterativePreOrder(Node<T> *temp){
    Stack<Node<T> *> S(10);
    while(temp != nullptr || !S.isEmpty()){
        if(temp != nullptr){
            cout<<temp->data<<" ";
            S.Push(temp);
            temp = temp -> Lchild;
        }
        else{
            S.Pop(temp);
            temp = temp->right;
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

int main(){
    BinaryTree<int> BT;
    Node<int> *P;
    P = BT.newNode(1); //P points to the newnode we created (1) -- root node
    P->Lchild = BT.newNode(2);
    P->Rchild = BT.newNode(3);
    P->Lchild->Lchild = BT.newNode(4);
    P->Lchild->Rchild = BT.newNode(5);
    P->Rchild->Lchild = BT.newNode(6);
    P->Rchild->Rchild = BT.newNode(7);
    cout<<"Recursive..."<<endl;
    cout<<"Inorder traversal: ";
    BT.TraverseInOrder(P);
    cout<<endl;
    cout<<"Preorder traversal: ";
    BT.TraversePreOrder(P);
    cout<<endl;
    cout<<"Postorder traversal: ";
    BT.TraversePostOrder(P);
    cout<<endl;
    cout<<"Iterative..."<<endl;
    cout<<"Inorder traversal: ";
    BT.TraverseInOrder(P);
    cout<<endl;
    cout<<"Preorder traversal: ";
    BT.TraversePreOrder(P);
    cout<<endl;
    cout<<"Height: "<<BT.Height(P);
    cout<<endl;
}


/*
                    1
                  /    \
                2        3
              /   \    /   \
            4      5  6     7
*/