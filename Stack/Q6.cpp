//Infix to Postfix without parenthesis
#include<bits/stdc++.h>
#include "samplestack.cpp"
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
    char Infix[10];
    char Postfix[10];
    cout<<"Enter Infix: ";
    cin>>Infix;
    int len = strlen(Infix);
    cout<<"length of Infix: "<<len<<endl;
    Infix[len] = '#';
    Infix[len+1] = '\0';

    Stack<char> S(10);
    S.Push('#');
    int i = 0, j = 0;
    char x;
    while(S.isEmpty() != true){
        if(Precedence(Infix[i]) > Precedence(S.TopElement())){
            S.Push(Infix[i]);
            i++;
        }
        else{
            S.Pop(x);
            Postfix[j] = x;
            j++;
        }
    }
    Postfix[j] = '\0';
    cout<<"Infix: "<<Infix<<endl;
    cout<<"Postfix: "<<Postfix<<endl;
}

//NOTE: IN OUTPUT POSTFIX AND INFIX RESULT ONE CAN REMOVE '#' TOO!!!