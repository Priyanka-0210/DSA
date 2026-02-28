//Create Stack that returns the Smallest Element in const time
#include<bits/stdc++.h>
#include "samplestack.cpp"
template<class T>
void Stack<T>::GetMin1(Stack<T> &t){
    if(t.TopElement() >= this->TopElement()){
        t.Push(this->TopElement());
        cout<<"Minimum so far in the stack: "<<t.TopElement()<<endl;
    }
}

int main(){
    Stack<int> s(10);
    Stack<int> t(10);
    int n,x;
    cin>>n;
    s.Push(n);
    t.Push(n);
    s.GetMin1(t);
    for(int i = 1; i < 5; i++){
        cin>>n;
        s.Push(n);
        s.GetMin1(t);
    }
    s.Pop(n);
    cout<<"After popping minimum: "<<endl;
    if(n == t.TopElement()) t.Pop(x);
    s.GetMin1(t);
}