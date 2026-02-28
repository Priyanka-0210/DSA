//Find the minimum and maximum in one scan to the array
#include<iostream>
using namespace std;
template<class T>
class ArrayADT{
    private:
    T *Arr;
    int size;
    public:
    ArrayADT(int size);
    void min_max(int size);
};

template<class T>
ArrayADT<T>::ArrayADT(int size){
    Arr = new T[size];
    cout<<"Enter "<<size<<" elements: ";
    for(int i=0;i<size;i++){
        cin>>Arr[i];
    }
}
template<class T>
void ArrayADT<T>::min_max(int size){
    int min = Arr[0],max = Arr[0];
    for(int i=1;i<size;i++){
        if(Arr[i] > max){
            max = Arr[i];
        }
        if(Arr[i] < min){
            min = Arr[i];
        }
    }
    cout<<"Maximum no in an array: "<<max<<endl;
    cout<<"Minimum no in an array: "<<min<<endl;
}

int main(){
    int size = 5;
    ArrayADT<int> A(size);
    A.min_max(size);
}

// one can also do like:
// for(int i=1;i<size;i++){
//     if(Arr[i] < min){
//         min = Arr[i];
//     }
//     else if(A[i] > max){
//         max = Arr[i];
//     }
// }

//if the elements are in ascending order conditions are checked two times Arr[i] < min and Arr[i] > max
//whereas if the elements are in descending order conditions are checked only one time - Do dry run
//in ascending if and else dono mai check karna pad raha hai whereas decreasing mai sirf else if wale ko 
//look in commented code

//Ascending order - worst case
//Descending order - best case
