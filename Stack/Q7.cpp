//Evaluating postfix expression
#include<iostream>
#include "samplestack.cpp"

int main(){
    Stack<int> s(20);
    char Postfix[20];
    cout<<"Enter Postfix: ";
    cin>>Postfix;
    int a,b, result;
    for(int i = 0; Postfix[i] != '\0'; i++){
        if(Postfix[i] >= 48 && Postfix[i] <= 57){
            s.Push(Postfix[i] - '0');
        }
        else{
            s.Pop(b);
            s.Pop(a);
            switch(Postfix[i]){
                case '+': result = a + b;
                            break;
                case '-': result = a - b;
                            break;
                case '*': result = a * b;
                            break;
            }
            s.Push(result);
        }
    }
    cout<<"Final result is: "<<result<<endl;
}