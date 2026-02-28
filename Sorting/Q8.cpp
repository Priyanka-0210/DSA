//Bin sort
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void Insert(Node ** ptrBins, int idx){
    Node *temp = new Node;
    temp->data = idx;
    temp->next = nullptr;
    if(ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;
    }
    else{
        Node *p = ptrBins[idx];
        while(p->next != nullptr){
            p = p -> next;
        }
        p->next = temp;
    }
}

int Delete(Node ** ptrBins, int idx){
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->data;
    delete p;
    return x;
}

void BinSort(int Arr[], int n){
    int max = -32678;
    for(int i = 0; i < n; i++){
        if(Arr[i] > max) max = Arr[i];
    }
    Node **bins = new Node *[max+1];
    for(int i = 0; i < max + 1; i++){
        bins[i] = nullptr;
    }
    for(int i = 0; i < n; i++){
        Insert(bins,Arr[i]);
    }
    int i = 0, j = 0;
    while(i <= max){
        while(bins[i] != nullptr){
            Arr[j] = Delete(bins,i);
            j++;
        }
        i++;
    }
    delete [] bins;
}

void Display(int Arr[], int n){
    for(int i = 0; i < n; i++){
        cout<<Arr[i]<<" ";
    }
}

int main(){
    int Arr[] = {2,5,7,3,3,8,1,0,6};
    cout<<"Before sorting: ";
    Display(Arr,9);
    BinSort(Arr,9);
    cout<<endl;
    cout<<"After sorting: ";
    Display(Arr,9);
}