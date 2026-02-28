//2 Stack using 1 array
#include<iostream>
using namespace std;

template<class T>
class Stack{
    private:
    T *Arr;
    int len1, len2;
    int size;
    int top1, top2;
    public:
    Stack(int size);
    ~Stack();
    void Push1(T element);
    void Pop1(T &element);
    void Push2(T element);
    void Pop2(T &element);
    void Display1();
    void Display2();
    int length();
};

template<class T>
Stack<T>::Stack(int size){
    this->size = size;
    Arr = new T(size);
    len1 = 0;
    len2 = 0;
    top1 = -1;
    top2 = size;
}

template<class T>
Stack<T>::~Stack(){
    delete [] Arr;
}

template<class T>
void Stack<T>::Push1(T element){
    if(!(top1 < top2 - 1)){
        cout<<"no space in array --- stack overflow"<<endl;
        return;
    }
    top1++;
    Arr[top1] = element;
    len1++;
}

template<class T>
void Stack<T>::Push2(T element){
    if(!(top1 < top2 - 1)){
        cout<<"no space in array --- stack overflow"<<endl;
        return;
    }
    top2--;
    Arr[top2] = element;
    len2++;
}

template<class T>
void Stack<T>::Pop1(T &element){
    if(top1 == -1){
        cout<<"stack underflow"<<endl;
        return;
    }
    element = Arr[top1];
    top1--;
    len1--;
}

template<class T>
void Stack<T>::Pop2(T &element){
    if(top1 == size){
        cout<<"stack underflow"<<endl;
        return;
    }
    element = Arr[top2];
    top2++;
    len2--;
}

template<class T>
void Stack<T>::Display1(){
    for(int i = top1; i >= 0; i--){
        cout<<Arr[i]<<" ";
    }
}

template<class T>
void Stack<T>::Display2(){
    for(int i = top2; i < size; i++){
        cout<<Arr[i]<<" ";
    }
}

int main(){
    int x;
    Stack<int> s(10);
    s.Push1(10);
    s.Push1(20);
    s.Push1(30);
    s.Push1(40);
    s.Push1(5);
    s.Push1(15);
    cout<<"Stack1 displayed: ";
    s.Display1();
    s.Push2(52);
    s.Push2(26);
    s.Push2(51);
    // s.Push2(15);
    // s.Push2(25);
    cout<<endl<<"Stack2 displayed: ";
    s.Display2();
    s.Pop1(x);
    cout<<endl<<"Deleted element from stack1: "<<x<<endl;
    cout<<"Stack1 displayed: ";
    s.Display1();
    s.Pop2(x);
    cout<<endl<<"Deleted element from stack2: "<<x<<endl;
    cout<<"Stack2 displayed: ";
    s.Display2();
}