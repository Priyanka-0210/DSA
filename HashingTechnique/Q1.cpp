//Hashing Technique -- Linear Probing
#include<iostream>
using namespace std;

class HashTable{
    int *Arr;
    int size;
    public:
        HashTable(int size);
        ~HashTable();
        void Insert(int key);
        int HashFunction(int key);
        int Search(int key);
        int LinearProbing(int key);
        void Display();
};

HashTable::HashTable(int size){
    this->size = size;
    Arr = new int[size];
    for(int i = 0; i < size; i++){
        Arr[i] = 0;
    }
}

HashTable::~HashTable(){
    delete [] Arr;
}

int HashTable::HashFunction(int key){
    return key % size;
}

int HashTable::LinearProbing(int key){
    int idx = HashFunction(key);
    //The Below code can't be used as say at index 5 collision is happening and I've size of 10
    //All the elements from index 5 to index 9 are full (the end of array is reached) thus I've to again start from the beginning
    //it's like a circled array.
    // for(int i = idx; i < size; i++){
    //     if(Arr[i] != 0) return i;
    // }
    //We use this code(shown below)
    int i = 0;
    while(Arr[(idx+i) % size] != 0){
        i++;
    }
    return (idx+i) % size;
    //Here we're assuming that an empty index exists.
}

void HashTable::Insert(int key){
    int idx = HashFunction(key);
    if(Arr[idx] != 0){
        idx = LinearProbing(key);
    }
    Arr[idx] = key;
}

int HashTable::Search(int key){
    int idx = HashFunction(key);
    int i = 0;
    while(i < size){
        if(Arr[(idx + i) % size] == key) return (idx + i) % size;
        if(Arr[(idx + i) % size] == 0) return -1;
        i++;
    }
}

void HashTable::Display(){
    for(int i = 0; i < size; i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    HashTable HT(10);
    cout<<"Enter 10 elements: ";
    int n;
    for(int i = 0; i < 10; i++){
        cin>>n;
        HT.Insert(n);
    }
    HT.Display();
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