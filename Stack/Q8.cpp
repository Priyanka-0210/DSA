//Parenthesis Matching
#include<iostream>
#include "samplestack.cpp"
int main(){
    string s = ")(((A+B)-C)+(D*E))-(F*G)";
    Stack<char> st(s.size());
    char ch,x;
    for(int i = 0; i < s.size(); i++){
        ch = s[i];
        if(ch == '('){
            st.Push(s[i]);
        }
        if(ch == ')'){
            if(st.isEmpty()){
                cout<<"Parenthesis doesn't match"<<endl;
                return 0;
            }
            st.Pop(x);
        }
    }
    if(!st.isEmpty()){
        cout<<"Parenthesis doesn't match..."<<endl;
    }
    else{
        cout<<"Parenthesis Matched!"<<endl;
    }
}