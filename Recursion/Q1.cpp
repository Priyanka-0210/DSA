//Palindrome using recursion
#include<bits/stdc++.h>
using namespace std;
bool palindrome(vector<int> arr, int start, int end);
int main(){
    vector<int> arr; int n, x;
    cout<<"Enter no elements: ";
    cin>>n;
    for(int i = 0; i< n; i++){
        cin>>x;
        arr.push_back(x);
    }
    if(palindrome(arr,0,arr.size()-1)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }
}
bool palindrome(vector<int> arr, int start, int end){
    if(start >= end) return true;
    if(arr[start] != arr[end]) return false;
    return palindrome(arr,start+1,end-1);
}