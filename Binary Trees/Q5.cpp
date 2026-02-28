//Binary Search Tree class ADT
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        Node<T> *Lchild;
        Node<T> *Rchild;
        T data;
};

template<class T>
class BST{
    private:
        Node<T> *root;
    public:
        BST();
        ~BST();
        Node<T> *GetRootElement();
        void Insert(int key);
        void Inorder(Node<T> *p);
        Node<T> *Search(int key);
        Node<T> *Delete(Node<T> *p, int key);
        Node<T> *InorderPredecessor(Node<T> *p);
        Node<T> *InorderSuccessor(Node<T> *p);
        int Height(Node<T> *p);
};

template<class T>
BST<T>::BST(){
    cout<<"Constructor is called! "<<endl;
    root = nullptr;
}

template<class T>
BST<T>::~BST(){
    cout<<"Destructor is called! "<<endl;
}

template<class T>
Node<T> * BST<T>::GetRootElement(){
    return root;
}

template<class T>
void BST<T>::Inorder(Node<T> *p){
    if(p != nullptr){
        Inorder(p -> Lchild);
        cout<<p->data<<" ";
        Inorder(p -> Rchild);
    }
}

template<class T>
void BST<T>::Insert(int key){
    Node<T> *temp = root;
    Node<T> *p, *r;
    if(root == nullptr){
        p = new Node<T>;
        p->data = key;
        p->Lchild = p->Rchild = nullptr;
        root = p;
        return;
    }

    while(temp != nullptr){
        r = temp;
        if(key < temp->data) temp = temp->Lchild;
        else if(key > temp->data) temp = temp->Rchild;
        else return;
    }

    p = new Node<T>;
    p->data = key;
    p->Lchild = p->Rchild = nullptr;
    if(key < r->data) r->Lchild = p;
    else r->Rchild = p;
}

template<class T>
Node<T> * BST<T>::Search(int key){
    Node<T> * temp = root;
    while(temp != nullptr){
        if(key == temp->data) return temp;
        else if(key < temp->data) temp = temp->Lchild;
        else temp = temp->Rchild;
    }
    return nullptr;
}

template<class T>
Node<T> * BST<T>::Delete(Node<T> *p,int key){
    Node<T> *q;
    if(p == nullptr) return nullptr;
    if(p->Lchild == nullptr && p->Rchild == nullptr && p->data == key){
        if(p == root) root = nullptr;
        delete p;
        return nullptr;
    }
    if(key < p->data){
        p->Lchild = Delete(p->Lchild,key);
    }
    else if(key > p->data){
        p->Rchild = Delete(p->Rchild,key);
    }
    else{
        if(Height(p->Lchild) > Height(p->Rchild)){
            q = InorderPredecessor(p->Lchild);
            p->data = q->data;
            p->Lchild = Delete(p->Lchild,q->data);
        }
        else{
            q = InorderSuccessor(p->Rchild);
            p->data = q->data;
            p->Rchild = Delete(p->Rchild,q->data);
        }
    }
    return p;
}

template<class T>
Node<T> *BST<T>::InorderPredecessor(Node<T> *p){
    while(p != nullptr && p->Rchild != nullptr){
        p = p->Rchild;
    }
    return p;
}

template<class T>
Node<T> *BST<T>::InorderSuccessor(Node<T> *p){
    while(p != nullptr && p->Lchild != nullptr){
        p = p->Lchild;
    }
    return p;
}

template<class T>
int BST<T>::Height(Node<T> *p){
    int l,r;
    if(p == nullptr) return 0;
    l = Height(p->Lchild);
    r = Height(p->Rchild);
    if(l > r) return l + 1;
    else return r+1;
}

int main(){
    BST<int> b;
    b.Insert(30);
    b.Insert(50);
    b.Insert(40);
    b.Insert(10);
    b.Insert(20);
    b.Insert(70);
    b.Inorder(b.GetRootElement());
    cout<<endl;
    b.Delete(b.GetRootElement(),30);
    b.Inorder(b.GetRootElement());
    cout<<endl;
    Node<int> *temp = b.Search(100);
    if(temp == nullptr){
        cout<<"Not found! "<<endl;
        return 0;
    }
    cout<<temp->data<<endl;
}