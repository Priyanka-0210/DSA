//Hashing Technique -- Chaining
#include<iostream>
using namespace std;

class Node{
    public:
        int Data;
        Node *next;
};

class HashTable{
    Node **Arr;
    int size;
    public:
        HashTable(int size);
        ~HashTable();
        void Insert(int key);
        int HashFunction(int key);
        int Search(int key);
};

HashTable::HashTable(int size){
    this->size = size;
    Arr = new Node* [size];
    for(int i = 0; i < size; i++){
        Arr[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for(int i = 0; i < size; i++){
        Node *temp = Arr[i];
        while(Arr[i] != nullptr){
            Arr[i] = Arr[i]->next;
            delete temp;
            temp = Arr[i];
        }
    }
    delete [] Arr;
}

int HashTable::HashFunction(int key){
    return key % size;
}

void HashTable::Insert(int key){
    int idx = HashFunction(key);
    Node *newnode = new Node;
    newnode->Data = key;
    newnode->next = nullptr;
    if(Arr[idx] == nullptr){
        Arr[idx] = newnode;
    }
    else{
        Node *p = Arr[idx];
        Node *q = Arr[idx];
        //Here we're making sure the data is getting inserted in sorted order
        while(p != nullptr && p->Data < key){
            q = p;
            p = p->next;
        }
        //Case 1: Inserting at first position
        if(q == Arr[idx]){
            newnode->next = Arr[idx];
            Arr[idx] = newnode;
        }
        //Case 2: Inserting in the middle or at last position
        else{
            newnode->next = q->next;
            q->next = newnode;
        }
    }

}

int HashTable::Search(int key){
    int idx = HashFunction(key);
    Node *temp = Arr[idx];
    while(temp != nullptr){
        if(temp->Data == key) return temp->Data;
        temp = temp->next;
    }
    return -1;
}

int main(){
    HashTable HT(10);
    cout<<"Enter 10 elements: ";
    int n;
    for(int i = 0; i < 10; i++){
        cin>>n;
        HT.Insert(n);
    }
    int x;
    cout<<"Enter search element: ";
    cin>>x;
    int search = HT.Search(x);
    if(search != -1){
        cout<<"Key Found at: "<<search<<endl;
    }
    else{
        cout<<"Key not found..."<<endl;
    }
}