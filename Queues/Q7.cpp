//Implementing Queue using STACK data structure - 1 Stack
#include<bits/stdc++.h>
using namespace std;

template<class T>
class QStack{
    public:
        stack<T> s;
        QStack(){};
        void EnQueue(T element);
        void DeQueue(T x);
        void Display();
};

template<class T>
void QStack<T>::EnQueue(T element){
    s.push(element);
}

template<class T>
void QStack<T>::DeQueue(T x){
    x = s.top();
    s.pop();
    if(s.empty()){
        cout<<"Element deleted: "<<x<<endl;
        return;
    }
    else{
        DeQueue(x);
        s.push(x);
    }
}

template<class T>
void QStack<T>::Display(){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    int x;
    QStack<int> QS;
    QS.EnQueue(10);
    QS.EnQueue(20);
    QS.EnQueue(30);
    QS.EnQueue(40);
    QS.DeQueue(x);
    QS.DeQueue(x);
    QS.Display();
    // QS.DeQueue(x);
    // QS.DeQueue(x);
}