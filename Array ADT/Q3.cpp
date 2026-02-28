//Special member functions --- shifting and rotating
#include<iostream>
using namespace std;
template<class T>
class ArrayADT{
    private:
    T *Arr;
    int size;
    int capacity;
    public:
    ArrayADT(int x);
    ~ArrayADT();
    void rotate_by_one_left();
    void rotate_by_three_left();
    void rotate_by_one_right();
    void rotate_by_three_right();
    void left_shift_by_one();
    void left_shift_by_two();
    void right_shift_by_one();
    void right_shift_by_two();
    void insert(int position,T element);
    void Display();
};

template<class T>
ArrayADT<T>:: ArrayADT(int x){
    cout<<"Constructor called \n";
    capacity = x;
    size = 0;
    Arr = new T[capacity];
}

template<class T>
ArrayADT<T>::~ArrayADT(){
    delete [] Arr;
    cout<<"Destructor called \n";
}

template<class T>
void ArrayADT<T>::rotate_by_one_left(){
    int temp = Arr[0]; int i;
    for(i=0;i<size-1;i++){
        Arr[i] = Arr[i+1];
    }
    Arr[i] = temp;
}

template<class T>
void ArrayADT<T>::rotate_by_three_left(){
    for(int i=0;i<3;i++){
        rotate_by_one_left();
    }
}

template<class T>
void ArrayADT<T>::rotate_by_one_right(){
    int temp = Arr[size-1]; int i;
    for(i=size-1;i>0;i--){
        Arr[i] = Arr[i-1];
    }
    Arr[i] = temp;
}

template<class T>
void ArrayADT<T>::rotate_by_three_right(){
    for(int i=0;i<3;i++){
        rotate_by_one_right();
    }
}

template<class T>
void ArrayADT<T>::left_shift_by_one(){
    for(int i=0;i<size-1;i++){
        Arr[i] = Arr[i+1];
    }
    size--;
}

template<class T>
void ArrayADT<T>::left_shift_by_two(){
    for(int i=0;i<2;i++){
        left_shift_by_one();
    }
}

template<class T>
void ArrayADT<T>::right_shift_by_one(){
    int i;
    for(i=size-1;i>0;i--){
        Arr[i] = Arr[i-1];
    }
    //(Arr[i] = 0; works only for int) hence we use Arr[i] = T()

    Arr[i] = T(); //Assign the default value of type T to Arr[i]
}

template<class T>
void ArrayADT<T>::right_shift_by_two(){
    for(int i=0;i<2;i++){
        right_shift_by_one();
    }
}

template<class T>
void ArrayADT<T>::insert(int position,T element){
    if(position < 1 || position > size + 1){
        cout<<"Invalid"<<endl;
        return;
    }
    for(int i = size-1; i>= position-1;i--){
        Arr[i+1] = Arr[i];
    }
    Arr[position-1] = element;
    size++;
}

template<class T>
void ArrayADT<T>::Display(){
    for(int i=0;i<size;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ArrayADT<int> A(10);
    A.insert(1,10);
    A.insert(2,20);
    A.insert(3,30);
    A.insert(4,40);
    A.insert(5,50);
    A.insert(6,60);
    A.insert(7,70);
    A.insert(8,80);
    A.Display();
    cout<<"\n";
    cout<<"Rotating by 1 position to the left: ";
    A.rotate_by_one_left();
    A.Display();
    cout<<"\n";
    cout<<"Rotating by 3 position to the left: ";
    A.rotate_by_three_left();
    A.Display();
    cout<<"\n";
    cout<<"Rotating by 1 position to the right: ";
    A.rotate_by_one_right();
    A.Display();
    cout<<"\n";
    cout<<"Rotating by 3 position to the right: ";
    A.rotate_by_three_right();
    A.Display();
    cout<<"\n";
    cout<<"Shifting by 1 position to the left: ";
    A.left_shift_by_one();
    A.Display();
    cout<<"\n";
    cout<<"Shifting by 2 position to the left: ";
    A.left_shift_by_two();
    A.Display();
    cout<<"\n";
    cout<<"Shifting by 1 position to the right: ";
    A.right_shift_by_one();
    A.Display();
    cout<<"\n";
    cout<<"Shifting by 2 position to the right: ";
    A.right_shift_by_two();
    A.Display();
}