//Reversing string using stack
#include<iostream>
#include "samplestack.cpp"
int main(){
    string s = "Priyanka";
    Stack<char> st(s.size());
    char ch, x;
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        ch = s[i];
        st.Push(ch);
    }
    for(int i = 0; i < s.size(); i++){
        st.Pop(x);
        ans = ans + x;
    }
    cout<<"Answer: "<<ans<<endl;
}