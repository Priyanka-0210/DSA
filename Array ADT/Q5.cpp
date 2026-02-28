//Linear search
#include<iostream>
using namespace std;
template<class T>
class LinearSearch{
    private:
    T *Arr;
    int size, key;
    public:
    LinearSearch(int size);
    void Linear(int size);
};

template<class T>
LinearSearch<T>::LinearSearch(int size){
    cout<<"Constructor called \n";
    Arr = new T[size];
}

template<class T>
void LinearSearch<T>:: Linear(int size){
    int key;
    bool flag = false;
    cout<<"Enter elements: ";
    for(int i=0;i<size;i++){
        cin>>Arr[i];
    }
    cout<<"Enter key: ";
    cin>>key;

    for(int i=0;i<size;i++){
        if(Arr[i] == key){
            flag = true;
            break;
        }
    }

    if(flag == true){
        cout<<"Key Found!"<<endl;
    }
    else{
        cout<<"Key not Found!"<<endl;
    }

}

int main(){
    int size;
    cout<<"Enter no of elements: ";
    cin>>size;
    LinearSearch<int> L(size);
    L.Linear(size);
}