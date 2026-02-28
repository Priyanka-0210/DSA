//Print all possible strings of length k that can be formed from a set of n characters
#include<bits/stdc++.h>
using namespace std;
void func(vector<char>sets,int n, int k, string s);
int main(){
    vector<char>sets;
    int k,n; char ch; string s = "";
    cout<<"Enter no of characters in sets: ";
    cin>>n;
    cout<<"Enter a number k: ";
    cin>>k;
    cout<<"Enter sets elements: ";
    for(int i=0;i<n;i++){
        cin>>ch;
        sets.push_back(ch);
    }
    func(sets,n,k,s);
}
void func(vector<char>sets, int n, int k, string s){
    if(k == 0){
        cout<<s<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        string news;
        news = s + sets[i];
        func(sets,n,k-1,news);
    }
}