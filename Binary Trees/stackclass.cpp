//Stack using array
#include<iostream>
using namespace std;

template<class T>
class Stack{
    private:
        T *Arr;
        int len;
        int Top;
        int size;
    public:
        Stack(int size);
        ~Stack();
        void Push(T element);
        void Pop(T &element);
        bool Find(int position, T &element);
        int Search(T element);
        int length();
        bool isEmpty();
        bool isFull();
        void Display();
};

template<class T>
Stack<T>::Stack(int size){
    this->size = size;
    Arr = new T(size);
    len = 0;
    Top = -1;
    cout<<"Constructor called...."<<endl;
}

template<class T>
Stack<T>::~Stack(){
    delete [] Arr;
    cout<<"Destructor called...."<<endl;
}

template<class T>
void Stack<T>::Push(T element){
    if(Top == (size-1)){
        cout<<"Stack overflow";
        return;
    }
    Top++;
    Arr[Top] = element;
    len++;
}

template<class T>
void Stack<T>::Pop(T &element){
    if(Top == -1){
        cout<<"Stack underflow";
        return;
    }
    element = Arr[Top];
    Top--;
    len--;
}

template<class T>
bool Stack<T>::Find(int position, T &element){
    if(position < 1 || position > (len+1)){
        cout<<"Invalid Position"<<endl;
        return false;
    }
    element = Arr[position - 1];
    return true;
}

template<class T>
int Stack<T>::Search(T element){
    for(int i = 0; i <= Top; i++){
        if(element == Arr[i]){
            return i+1; //returning position
        }
    }
    return -1; //unsuccessful search
}

template<class T>
int Stack<T>::length(){
    return len;
}

template<class T>
bool Stack<T>::isEmpty(){
    return (Top == -1);
}

template<class T>
bool Stack<T>::isFull(){
    return (Top == size-1);
}


//i'm printing from last to front following LIFO one can print from front to last too
template<class T>
void Stack<T>::Display(){
    for(int i = Top; i >= 0; i--){
        cout<<Arr[i]<<" ";
    }
}

// int main(){
//     int x;
//     Stack<int> s(6);
//     s.Push(10);
//     s.Push(20);
//     s.Push(30);
//     s.Push(40);
//     s.Push(50);
//     s.Display();
//     cout<<"\n";
//     s.Pop(x);
//     s.Display();
//     cout<<"Deleted element: "<<x<<endl;
//     cout<<"find operation: "<<s.Find(2,x)<<"found element at 2: "<<x<<endl;
//     cout<<"element found in Search operation at: "<<s.Search(40)<<endl;
//     cout<<"length: "<<s.length()<<endl;
//     cout<<"isempty(): "<<s.isEmpty()<<endl;
//     cout<<"isFull(): "<<s.isFull()<<endl;
// }