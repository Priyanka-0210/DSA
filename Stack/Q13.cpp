//Solution to Coding Challenge that returns the Smallest Element with One stack
#include<bits/stdc++.h>
#include "samplestack.cpp"
template<class T>
int Stack<T>::GetMin2(int n, int min){
    if(n < min){
        this->Push((2*n) - min);
        cout<<"Top: "<<this->TopElement()<<endl;
        min = n;
        return min;
    }
    else{
        return min;
    }
}

int main(){
    Stack<int> s(10);
    int min,n,x;
    cin>>n;
    min = n;
    for(int i = 1; i < 5; i++){
        cin>>n;
        min = s.GetMin2(n,min);
    }
    cout<<"Min: "<<min<<endl;
    if(s.TopElement() < min){
        min = (2 * min) - s.TopElement();
        s.Pop(x);
        cout<<"Min at instance : "<<min<<endl;
    }
    else{
        cout<<"Min: "<<min<<endl;
    }
}