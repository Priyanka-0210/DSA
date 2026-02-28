//Implementing Queue using STACK data structure - 2 Stacks
//Enqueue takes O(1) and Dequeue takes O(n)
#include<bits/stdc++.h>
using namespace std;

template<class T>
class QStack{
    public:
        stack<T> stack1, stack2;
        QStack(){} 
        void Enqueue(T element);
        void Dequeue(T &element);
        void Display();
};

template<class T>
void QStack<T>::Enqueue(T element){
    stack1.push(element);
}

template<class T>
void QStack<T>::Dequeue(T &element){
    if(stack1.empty()){
        cout<<"Queue is empty! "<<endl;
        return;
    }
    T x;
    while(!stack1.empty()){
        x = stack1.top();
        stack1.pop();
        stack2.push(x);
    }
    element = stack2.top();
    stack2.pop();
    while(!stack2.empty()){
        x = stack2.top();
        stack2.pop();
        stack1.push(x);
    }
    cout<<"deleted element: "<<element<<endl;
}

template<class T>
void QStack<T>::Display(){
    while(!stack1.empty()){
        cout<<stack1.top()<<" ";
        stack1.pop();
    }
}

int main(){
    int n;
    QStack<int> QS;
    for(int i = 0; i < 5; i++){
        cin>>n;
        QS.Enqueue(n); //Time complexity: O(1)
    }
    // QS.Display(); -- Use to check the elements in QS, I've commented 
    //because in display function we'r popping the elements too and I wanted to demonstrate dequeue function..
    cout<<"Deleting element......"<<endl; 
    QS.Dequeue(n); //Time complexity: O(n)
    QS.Display();
}