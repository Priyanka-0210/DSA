//Infix to Postfix without parenthesis
#include<bits/stdc++.h>
#include "samplestack.cpp"
using namespace std;

//before executing this code make sure main function in Q1.cpp is commented out
//cause compiler will through error if it finds two main function

int Precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '#'){
        return 0;
    }
    else{
        return 3;
    }
}

int main(){
    int len,i = 0,j = 0;
    char x;
    char Infix[10];
    char Postfix[10];
    cout<<"Enter infix: ";
    cin>>Infix;
    len = strlen(Infix);
    Infix[len] = '#';
    Infix[len + 1] = '\0';
    Stack<char> s(10);
    s.Push('#');
    while(!s.isEmpty()){
        if(Precedence(Infix[i]) > Precedence(s.TopElement())){
            s.Push(Infix[i]);
            i++;
        }
        else{
            s.Pop(x);
            Postfix[j] = x;
            j++;
        }
    }
    Postfix[j] = '\0';
    cout<<"Infix: "<<Infix<<endl;
    cout<<"Postfix: "<<Postfix<<endl;
    cout<<"without # at the end..."<<endl;
    cout<<"Infix: ";
    i = 0;
    while(Infix[i] != '#'){
        cout<<Infix[i];
        i++;
    }
    cout<<endl<<"Postfix: ";
    i = 0;
    while(Postfix[i] != '#'){
        cout<<Postfix[i];
        i++;
    }
    cout<<"\n";
}