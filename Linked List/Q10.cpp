//Intersection point of two linked lists
#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int coeff;
    int exp;
};

class Poly{
    public:
    Node *head;
    int len;
    Poly();
    ~Poly();
    void addition(Node *LL1,Node *LL2);
    void Insert(int position,int coeff, int exp);
    void Display();
};

Poly::Poly(){
    head = nullptr;
    len = 0;
    cout<<"Constructor called..."<<endl;
}

Poly::~Poly(){
    Node *temp = head;
    while(head != nullptr){
        head = head -> next;
        delete temp;
        temp = head;
    }
    cout<<"Destructor called..."<<endl;
}

void Poly::Insert(int position, int coeff, int exp){
    Node *newnode;
    newnode = new Node;
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = nullptr;
    if(head == nullptr){ // one can also check like if(len == 0){  }
        head = newnode;
    }
    else{
        if(position == 1){
            newnode->next = head;
            head = newnode;
        }
        else if(position == (len + 1)){ // one can also use traversal method
            Node *temp = head;
            while(temp -> next != nullptr){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        else{
            Node *temp;
            temp = head;
            for(int i = 1; i < position - 1; i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    len++;
}

void Poly::addition(Node *LL1,Node *LL2){
    Node *temp1 = LL1;
    Node *temp2 = LL2;
    Node *temp;
    int a,b,c,d;
    while(temp1 != nullptr && temp2 != nullptr){ 
//I can't use || here because if one of the temp1 or temp2 gets nullptr we can't access temp1->exp 
//thus we use && and then we check for remaining elements at the end
        Node *newnode = new Node;
        newnode->next = nullptr;
        if(head == nullptr){
            this->head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
        a = temp1->exp;
        b = temp2->exp;
        c = temp1->coeff;
        d = temp2->coeff;
        if(a == b){
            newnode->exp = a;
            newnode->coeff = (c + d);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else{
            if(a > b){
                newnode->exp = a;
                newnode->coeff = c;
                temp1 = temp1 -> next;
            }
            else{
                newnode->exp = b;
                newnode->coeff = d;
                temp2 = temp2 -> next;
            }
        }
        len++;
    }
    while(temp1 != nullptr){
        Node *newnode = new Node;
        newnode->next = nullptr;
        temp->next = newnode;
        newnode->coeff = temp1->coeff;
        newnode->exp = temp1->exp;
        temp = temp->next;
        temp1 = temp1 -> next;
        len++;
    }
        while(temp2 != nullptr){
        Node *newnode = new Node;
        newnode->next = nullptr;
        temp->next = newnode;
        newnode->coeff = temp2->coeff;
        newnode->exp = temp2->exp;
        temp = temp->next;
        temp2 = temp2 -> next;
        len++;
    }
}

void Poly::Display(){
    Node *temp = head;
    while(temp != nullptr){
        cout<<"coeff: "<<temp->coeff<<" "<<"exp: "<<temp->exp<<endl;
        temp = temp -> next;
    }
}

int main(){
    Poly LL1,LL2,add;
    LL1.Insert(1,3,4);
    LL1.Insert(2,5,2);
    LL1.Insert(3,9,0);
    LL2.Insert(1,6,4);
    LL2.Insert(2,7,3);
    LL2.Insert(3,3,2);
    LL2.Insert(4,4,0);
    LL1.Display();
    LL2.Display();
    cout<<"Result: "<<endl;
    add.addition(LL1.head,LL2.head);
    add.Display();
    return 0;
}