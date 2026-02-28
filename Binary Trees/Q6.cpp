//AVL Class ADT
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node<T> *Lchild;
        Node<T> *Rchild;
        int height;
};

template<class T>
class AVL{
    public:
        ~AVL();
        AVL();
        Node<T> *root;
        int Node_Height(Node<T> *p);
        int BalanceFactor(Node<T> *p);
        Node<T> * LL_Rotation(Node<T> *p);
        Node<T> * LR_Rotation(Node<T> *p);
        Node<T> * RR_Rotation(Node<T> *p);
        Node<T> * RL_Rotation(Node<T> *p);
        Node<T> * Insert(Node<T> *p, T key);
        void Inorder(Node<T> *p);
        Node<T> * getRoot();
};

//Calculates height of every node
template<class T>
int AVL<T>::Node_Height(Node<T> *p){
    int l,r;
    if(p == nullptr) return 0;
    l = Node_Height(p->Lchild);
    r = Node_Height(p->Rchild);
    if(l > r) return l + 1;
    else return r+1;
}

// //Above Node_Height code is same as this:
// height(NULL) = 0
// height(node) = 1 + max(height(left child), height(right child))

template<class T>
int AVL<T>::BalanceFactor(Node<T> *p){
    int height_leftsubtree, height_rightsubtree;

    if(p != nullptr && p->Lchild != nullptr){
        height_leftsubtree = p->Lchild->height;
    }
    else{
        height_leftsubtree = 0;
    }

    if(p != nullptr && p->Rchild != nullptr){
        height_rightsubtree = p->Rchild->height;
    }
    else{
        height_rightsubtree = 0;
    }

    return height_leftsubtree - height_rightsubtree;
}

//p = node itself, pl = left child of p, plr = right child of pl
template<class T>
Node<T> * AVL<T>::LL_Rotation(Node<T> *p){
    Node<T> *pl = p->Lchild;
    Node<T> *plr = pl->Rchild;
    pl->Rchild = p;
    p->Lchild = plr;
    p->height = Node_Height(p);
    pl->height = Node_Height(pl);
    
    if(root == p) root = pl; //if p is root
    return pl;
}

//p = node itself, pl = left child of p, plr = right child of pl
template<class T>
Node<T> * AVL<T>::LR_Rotation(Node<T> *p){
    Node<T> *pl = p->Lchild;
    Node<T> *plr = pl->Rchild;
    pl->Rchild = plr->Lchild;
    p->Lchild = plr->Rchild;
    plr->Lchild = pl;
    plr->Rchild = p;
    pl->height = Node_Height(pl);
    p->height = Node_Height(p);
    plr->height = Node_Height(plr);

    if(root == p) root = plr;
    return plr;
}

//p - node itself, pr - right child of p, prl - left child of pr
template<class T>
Node<T> * AVL<T>::RR_Rotation(Node<T> *p){
    Node<T> *pr = p->Rchild;
    Node<T> *prl = pr->Lchild;
    pr->Lchild = p;
    p->Rchild = prl;
    p->height = Node_Height(p);
    pr->height = Node_Height(pr);
    if(root == p) root = pr;
    return pr;
}

//p - node itself, pr - right child of p, prl - left child of pr
template<class T>
Node<T> * AVL<T>::RL_Rotation(Node<T> *p){
    Node<T> *pr = p->Rchild;
    Node<T> *prl = pr->Lchild;
    pr->Lchild = prl->Rchild;
    p->Rchild = prl->Lchild;
    prl->Lchild = p;
    prl->Rchild = pr;
    p->height = Node_Height(p);
    pr->height = Node_Height(pr);
    prl->height = Node_Height(prl);
    if(root == p) root = prl;
    return prl;
}

template<class T>
Node<T> * AVL<T>::Insert(Node<T> *p, T key){
    Node<T> *temp;
    if(p == nullptr){
        temp = new Node<T>;
        temp->Lchild = nullptr;
        temp->Rchild = nullptr;
        temp->height = 1; //we can have either 0 or 1 (choice is ours)
        temp->data = key;
        return temp;
    }

    if(key < p->data){
        p->Lchild = Insert(p->Lchild,key);
    }
    else if(key > p->data){
        p->Rchild = Insert(p->Rchild,key);
    }
    
    p->height = Node_Height(p);

    //LL rotation is called when balance factor for root node is 2 and balance factor of it's left child is 1
    if(BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == 1){
        return LL_Rotation(p);
    }
    //RR rotation is called when balance factor for root node is -2 and balance factor of it's right child is -1
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == -1){
        return RR_Rotation(p);
    }
    //LR rotation is called when balance factor for root node is 2 and balance factor of it's left child is -1
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == -1){
        return LR_Rotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == 1){
        return RL_Rotation(p);
    }
    return p;
}

template<class T>
void AVL<T>::Inorder(Node<T> *p){
    if(p != nullptr){
        Inorder(p->Lchild);
        cout<<p->data<<" ";
        Inorder(p->Rchild);
    }
}

template<class T>
Node<T> * AVL<T>::getRoot(){
    return root;
}

template<class T>
AVL<T>::~AVL(){
    cout<<"Destructor is called..."<<endl;
}

template<class T>
AVL<T>::AVL(){
    root = nullptr;
    cout<<"Constructor is called..."<<endl;
}

int main(){
    AVL<int> ALL;
    ALL.root = ALL.Insert(ALL.root,30);
    ALL.root =  ALL.Insert(ALL.root,25);
    ALL.root = ALL.Insert(ALL.root,20);
    cout<<"Balanced BST LL: ";
    ALL.Inorder(ALL.root);
    cout<<endl;
    cout<<"Root: "<<ALL.root->data<<endl;

    AVL<int> ARR;
    ARR.root = ARR.Insert(ARR.root,5);
    ARR.root = ARR.Insert(ARR.root,10);
    ARR.root = ARR.Insert(ARR.root,20);
    cout<<"Balanced BST RR: ";
    ARR.Inorder(ARR.root);
    cout<<endl;
    cout<<"Root: "<<ARR.root->data<<endl;

    AVL<int> ALR;
    ALR.root = ALR.Insert(ALR.root,40);
    ALR.root = ALR.Insert(ALR.root,25);
    ALR.root = ALR.Insert(ALR.root,30);
    cout<<"Balanced BST LR: ";
    ALR.Inorder(ALR.root);
    cout<<endl;
    cout<<"Root: "<<ALR.root->data<<endl;

    AVL<int> ARL;
    ARL.root = ARL.Insert(ARL.root,100);
    ARL.root = ARL.Insert(ARL.root,200);
    ARL.root = ARL.Insert(ARL.root,150);
    cout<<"Balanced BST RL: ";
    ARL.Inorder(ARL.root);
    cout<<endl;
    cout<<"Root: "<<ARL.root->data<<endl;
}